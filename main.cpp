#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLCDNumber>
#include <QProgressBar>
#include <QMessageBox>



void OnClickBtn1();
void OnClickBtn2();
void OnClickBtn3();
void OnClickBtn4();
void OnClickBtn5();

int pr = 0; //��� Progress Bar
int lc = 0; //��� LCD Number



int main(int argc, char* argv[]) {

	QApplication a(argc, argv);
	a.processEvents();

	QWidget* widget = new QWidget;
	widget->setMinimumSize(350, 200);

	QGridLayout* layout = new QGridLayout(); //����� ����
	QHBoxLayout* layout1 = new QHBoxLayout(); //���� �� ������
	QVBoxLayout* layout2 = new QVBoxLayout(); //���� � ������������
	QHBoxLayout* layout3 = new QHBoxLayout(); //���� � �������
	QHBoxLayout* layout4 = new QHBoxLayout(); //���� � �������
	QVBoxLayout* layout5 = new QVBoxLayout(); //���� � �������� � ��� ��������
	QHBoxLayout* layout6 = new QHBoxLayout(); //���� � �������� "� ���������" � "�������"
	QHBoxLayout* layout7 = new QHBoxLayout(); //���� � ������� "�����������"

	QLabel* login = new QLabel();
	QLabel* password = new QLabel();

	login->setText(QString::fromLocal8Bit("��� ������������:"));
	password->setText(QString::fromLocal8Bit("������:"));

	QLineEdit* login_l = new QLineEdit();
	QLineEdit* password_l = new QLineEdit();

	

	QPushButton* btn1 = new QPushButton(QString::fromLocal8Bit("��������� 1"));
	QPushButton* btn2 = new QPushButton(QString::fromLocal8Bit("��������� 3"));
	QPushButton* btn3 = new QPushButton(QString::fromLocal8Bit("��������� 10"));
	QPushButton* btn4 = new QPushButton(QString::fromLocal8Bit("�����������"));
	QPushButton* btn5 = new QPushButton(QString::fromLocal8Bit("� ���������"));
	QPushButton* btn6 = new QPushButton(QString::fromLocal8Bit("�������"));


	QLCDNumber* lcdnum = new QLCDNumber(widget);
	QProgressBar* progbar = new QProgressBar(widget);

	widget->setLayout(layout);

	layout1->addWidget(progbar);
	layout2->addStretch();
	layout2->addLayout(layout3);
	layout2->addLayout(layout4);
	layout2->addLayout(layout7);
	layout2->addStretch(20);
	layout3->addSpacing(40);
	layout3->addWidget(login);
	layout3->addWidget(login_l);
	layout4->addSpacing(40);
	layout4->addWidget(password);
	layout4->addWidget(password_l);
	layout5->addWidget(lcdnum);
	layout5->addWidget(btn1);
	layout5->addWidget(btn2);
	layout5->addWidget(btn3);
	layout6->addSpacing(40);
	layout6->addWidget(btn5);
	layout6->addWidget(btn6);
	layout7->addSpacing(40);
	layout7->addWidget(btn4);

	layout->addLayout(layout1, 1, 1, 1, 4);
	layout->addLayout(layout5, 2, 1);
	layout->addLayout(layout2, 2, 2);
	layout->addLayout(layout6, 3, 2);

	progbar->setValue(pr);
	lcdnum->setDigitCount(4);
	lcdnum->display(QString::number(lc));
	widget->show();

	//������  "��������� 1"
	widget->connect(btn1, &QPushButton::clicked, OnClickBtn1);
	widget->connect(btn1, &QPushButton::clicked, progbar, [=] {progbar->setValue(pr); });
	widget->connect(btn1, &QPushButton::clicked, lcdnum, [=] {lcdnum->display(QString::number(lc)); });

	//������ "��������� 3"
	widget->connect(btn2, &QPushButton::clicked, OnClickBtn2);
	widget->connect(btn2, &QPushButton::clicked, progbar, [=] {progbar->setValue(pr); });
	widget->connect(btn2, &QPushButton::clicked, lcdnum, [=] {lcdnum->display(QString::number(lc)); });

	//������ "��������� 10"
	widget->connect(btn3, &QPushButton::clicked, OnClickBtn3);
	widget->connect(btn3, &QPushButton::clicked, progbar, [=] {progbar->setValue(pr); });
	widget->connect(btn3, &QPushButton::clicked, lcdnum, [=] {lcdnum->display(QString::number(lc)); });

	//������ "�����������"
	widget->connect(btn4, &QPushButton::clicked, OnClickBtn4);
	widget->connect(btn4, &QPushButton::clicked, progbar, [=] {progbar->setValue(pr); });
	widget->connect(btn4, &QPushButton::clicked, widget, [=] {if ((login_l->text() == "Panorama") && (password_l->text() == "test")) { QMessageBox msgBox; msgBox.information(widget, QString::fromLocal8Bit("�����!"), QString::fromLocal8Bit("����� � ������ �����. ���� ����� �������.")); progbar->setValue(100); } else {QMessageBox msgBox; msgBox.critical(widget, QString::fromLocal8Bit("��������!"), QString::fromLocal8Bit("������������ ���� ����� � ������. ���������� ��� ���."));}});

	//������ "� ���������"
	widget->connect(btn5, &QPushButton::clicked, OnClickBtn5);

	//������ "�������"
	widget->connect(btn6, &QPushButton::clicked, widget, &QWidget::close);

	//����� ��������� �� 100%
	widget->connect(progbar, &QProgressBar::valueChanged, [=] {int n = 100; if (n == progbar->value()) { widget->close(); }});
	

	return a.exec();
}

void OnClickBtn1()
{
	pr++;
	lc++;
}

void OnClickBtn2()
{
	pr++;
	lc += 3;
}

void OnClickBtn3()
{
	pr++;
	lc += 10;
}

void ::OnClickBtn4()
{
	pr++;
}

void OnClickBtn5()
{
	QWidget* widget1 = new QWidget;
	QMessageBox::about(widget1, QString::fromLocal8Bit("� ���������"), QString::fromLocal8Bit("��� ������� ����� � ������������ ������� �������� �� QT � Visual Studio. ��� ���������� ����� ��������� 100%, ���� ���������. �����: Panorama, ������: test."));
}

