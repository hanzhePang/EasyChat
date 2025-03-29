#include "denglu.h"
#include "ui_denglu.h"
#include<QIcon>
#include<QToolButton>
#include"widget.h"
#include<QMessageBox>

//void MainWindow::setApplicationIcon() {
//    QIcon icon(":/picture/huojian.ico.ico");
//    QApplication::setWindowIcon(icon);
//}

denglu::denglu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::denglu)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/picture/huojian.png"));//tubiao
    this->setWindowTitle("庞涵哲");
    QList<QString>nameList;
    nameList<<"迪士尼在逃普信男"<<"我在打灰挺好的"<<"叙利亚大兵罗杰斯"<<"德克萨斯州警长布莱尔"<<"头都大了"<<"我就是喜欢修理地球"<<"上善若水,花开富贵"<<"郑州市精神病院副院长杰克·布鲁斯"<<"超人他会飞";
    QStringList iconNameList;
    iconNameList<<"cat"<<"down man"<<"pngimg.com - soldier_PNG16079"<<"pngimg.com - policeman_PNG89074"
                 <<"man"<<"pngimg.com - farmer_PNG21"<<"pngpai.com_bouquet-of-flowers-26943"
                 <<"pngpai.com_doctors-and-nurses-40684"<<"super gays";
    QVector<QToolButton *>vector;
    for(int i=0;i<9;i++)
    {
        QToolButton* btn=new QToolButton(this);//加载图标
        //btn->setIcon(QPixmap(":/picture/super gays.png"));
        //btn->setIconSize(QPixmap(":/picture/super gays.png").size());
        btn->setIcon(QPixmap(QString(":/picture/%1.png").arg(iconNameList[i])));
        //btn->setIconSize(QPixmap(QString(":/picture/%1.png").arg(iconNameList[i])).size());
        btn->setIconSize(QSize(129, 90));
        btn->setText(QString("%1").arg(nameList[i]));
        btn->setFont(QFont("微软雅黑", 9));
        btn->setAutoRaise(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui->vlayout->addWidget(btn);
        vector.push_back(btn);
        IsShow.push_back(false);
    }

    for(int i=0;i<9;i++)
    {
        connect(vector[i],&QToolButton::clicked,[=](){
            if(IsShow[i])
            {
                QMessageBox::warning(this,"提示","该聊天框已打开");
                return ;
            }
            IsShow[i]=true;
            Widget *widget=new Widget(nullptr,vector[i]->text());
            widget->setWindowIcon(vector[i]->icon());
            widget->setWindowTitle(vector[i]->text());
            widget->show();
            //关闭窗口事件
            connect(widget,&Widget::closeWidget,this,[=](){
                IsShow[i]=false;
            });
        });
    }
}

denglu::~denglu()
{
    delete ui;
}
