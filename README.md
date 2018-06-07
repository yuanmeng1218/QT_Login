一.使用设计模式创建界面
1.在项目创建完成后，向项目中添加新的Qt设计师界面类，然后可以添加控件。
2.在属性编辑器中可以修改控件的name。
3.使用一种信号和槽关联的方法来设置退出按钮：
	——在设计模式下方的信号和槽编辑器中：
	发送者是exitBtn，信号为clicked(),接收者为LoginDialog,槽位close().
	单击退出按钮时，就会关闭登录对话框。
		 
4.右击登录按钮，选择“转到槽”，然后选择clicked信号并确定，然后添加函数调用：accept()
5.在main.cpp文件中判断是否点击了“登录”，进行窗口的切换：dlg.exec() == QDialog::Accepted
6.在logindialog.cpp文件中判断登录信息是否正确，分别采取不同的操作。
警告：QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误"),QMessageBox::Yes)
7.密码格式：在属性编辑器中将echoMode属性选择为Password
8.提示语句：将编辑器的placeholderText属性更改为“请输入用户名”
9.去除字符串前后的空白字符：ui->usrLineEdit->text().trimmed()
10.清除内容并定位光标：ui->usrLineEdit->clear(),ui->usrLineEdit->setFocus()

二.纯代码编写
1.新建Qt Widgets Application时，取消选择创建界面选项
2.创建登录对话框：往项目中添加新文件，模板选择c++ class
3.在类定义界面，基类选择Custom定制，然后手动设置为QDialog
4.在logindialog.h文件中声明构造函数，定义一些部件对象的指针；LoginDialog类声明的开始需要添加Q_OBJECT宏才能使用信号和槽等元对象系统功能。
5.在logindialog.cpp文件中对界面部件对象初始化
6.在main.cpp中显示界面
7.实现两个按钮的功能，按钮的功能是通过信号和槽来实现的：
	——首先在logindialog.h文件中在类的声明最后添加
		private slots: void login();//声明槽
	——在logindialog.cpp文件中在构造函数的最后添加：
		connect(发射信号的部件，发射的信号，接受信号的部件，要执行的槽)
8.在logindialog.cpp文件最后添加槽的定义，即点击“登录”按钮之后进行的操作。这时部件调用不需要使用ui对象


——设置信号和槽的关联：
1.	点击设计模式上方的 图标，进入信号和槽编辑模式，按着鼠标左键，从按钮上拖向界面。
 
	放开鼠标后，选择pushButton的clicked()信号和LoginDlg的accept()槽并按下确定按钮。一般情况下，我们只需要修改槽函数即可。槽函数实现了指定的功能之后会返回QDialog::Accepted标识。
2.在“按钮”部件上右击并选择转到槽菜单，然后选择第一个clicked信号，会转到自动生成槽的位置
