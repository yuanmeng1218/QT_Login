#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    //判断用户名和密码是否正确。如果错误则弹出警告对话框
    if(ui->usrLineEdit->text().trimmed() == tr("yuanmeng") && ui->pwdLineEdit->text() == tr("123"))
    {
        accept();
    }else{
        //其中的参数依次是：this表明父窗口是登录对话框、窗口标题、界面显示的内容和最后要显示的按钮，这里使用了一个Yes按钮
        QMessageBox::warning(this,tr("警告"),tr("用户名和密码错误"),QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}
