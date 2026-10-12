#include "cbuildindialog.h"

CBuiltinDialog::CBuiltinDialog(QWidget *parent)//建構函數
    : QDialog(parent)
{
    QGridLayout* gridLayout =new QGridLayout;
    displayTextEdit=new QTextEdit(QStringLiteral("Qt的標準通用對話盒"));//產生物件實體於記憶體中，將記憶體的位置存於displayTextEdit變數
    colorPushBtn=new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBtn=new QPushButton(QStringLiteral("錯誤訊息盒"));
    filePushBtn=new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBtn=new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBtn=new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBtn=new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushBtn=new QPushButton(QStringLiteral("進度對話盒"));
    printPushBtn=new QPushButton(QStringLiteral("列印對話盒"));
    fontcolorPushBtn=new QPushButton(QStringLiteral("文字顏色對話盒"));




    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(fontcolorPushBtn,2,2,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);

    setLayout(gridLayout);
    setWindowTitle(QStringLiteral("內建對話盒展示"));
    resize(400,300);

    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontcolorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));

}

CBuiltinDialog::~CBuiltinDialog() = default;//結構函數

void CBuiltinDialog :: doPushBtn()//槽結構實作
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn==colorPushBtn){
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
        QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("設定背景顏色"));

        if(color.isValid())
        {

            palette.setColor(QPalette::Base,color);
            displayTextEdit->setPalette(palette);
        }
    }
    if (btn == filePushBtn)
    {
       QString fileName = QFileDialog::getOpenFileName(this,"挑選檔案",".","任何檔案(*.*);;文字檔(*.txt);;HTML檔(*.html)");
       displayTextEdit->setText(fileName);
        /*QString fileName = QFileDialog::getOpenFileName(this,"挑選檔案",".");
        displayTextEdit->setText(fileName);*/
    }

    if(btn == errorPushBtn)
    {
        QErrorMessage box(this);
        box.setWindowTitle(QStringLiteral("錯誤信息盒實例xx:"));
        box.setWindowTitle(QStringLiteral("錯誤信息盒實例yy:"));
        box.setWindowTitle(QStringLiteral("錯誤信息盒實例zz:"));
        box.exec();
    }
    if (btn==fontcolorPushBtn){
        QPalette palette=displayTextEdit->palette();
        const QColor& color=
            QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("設定文字顏色"));

        if(color.isValid())
        {

            palette.setColor(QPalette::Text,color);
            displayTextEdit->setPalette(palette);
        }
    }
}