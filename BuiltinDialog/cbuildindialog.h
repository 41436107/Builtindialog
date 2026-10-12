#ifndef CBUILDINDIALOG_H
#define CBUILDINDIALOG_H

#include <QDialog>
#include<QtWidgets>
class CBuiltinDialog : public QDialog
{
    Q_OBJECT//一個Qt定義的巨集

public:
    explicit CBuiltinDialog(QWidget *parent = nullptr);
    ~CBuiltinDialog() override;

private:
    QTextEdit*  displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* fontPushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
    QPushButton* fontcolorPushBtn;
private slots:
    void doPushBtn();
};
#endif // CBUILDINDIALOG_H
