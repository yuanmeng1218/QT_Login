#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent):QDialog(parent)
{
    usrLabel = new QLabel(this);
    usrLabel->move(70,80);//将部件左上角的坐标设置为（70，80）
    usrLabel->setText(tr("用户名："));
    usrLineEdit = new QLineEdit(this);
    usrLineEdit->move(140,80);
    usrLineEdit->setPlaceholderText("请输入用户名");

    pwdLabel = new QLabel(this);
    pwdLabel->move(70,130);
    pwdLabel->setText(tr("密码："));
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140,130);
    pwdLineEdit->setPlaceholderText("请输入密码");
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    loginBtn = new QPushButton(this);
    loginBtn->move(50,200);
    loginBtn->setText(tr("登录"));
    exitBtn = new QPushButton(this);
    exitBtn->move(210,200);
    exitBtn->setText(tr("退出"));

    connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::login);
    connect(exitBtn,&QPushButton::clicked,this,&LoginDialog::close);
}
LoginDialog::~LoginDialog()
{

}
void LoginDialog::login()
{
    //判断用户名和密码是否正确，如果错误则弹出警告对话框
    if(usrLineEdit->text().trimmed() == tr("yuanmeng") && pwdLineEdit->text() == tr("123456"))
    {
        accept();
    }else{
        QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误"),QMessageBox::Yes);
        usrLineEdit->clear();
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}
