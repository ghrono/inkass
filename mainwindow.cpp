#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>


QString Numb_to_word(QString number);

void write(QString filename)
{
    QFile mfile(filename);
    if (!mfile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "ne otkrivaecco dlya zapisi";
        return;
    }
    QTextStream out(&mfile);
    out << "helow world";
    mfile.flush();
    mfile.close();
}
void read(QString filename)
{

    QFile mfile(filename);
    if (!mfile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "ne otkrivaecco dlya chtrniya";
        return;
    }
    QTextStream in(&mfile);
    QString mtext = in.readAll();
    qDebug() << "testt";
    printf("%s",mtext.toStdString().c_str());
    mfile.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   QString mFilename = "sett.ini";
   write(mFilename);
 //   read(mFilename);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   double z = 0;

   for ( int i = 0; i < 14; i++ )
   {
   QString cen = ui->tableWidget->item(i,0)->text();
   QString sht = ui->tableWidget->item(i,1)->text();
   double itog = sht.toInt()*cen.toDouble();
   z=z+itog;
   ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::number(itog, 'f', 2)));
   }

   QTextCodec *utfcodec = QTextCodec::codecForName("UTF-8");
   QTextCodec::setCodecForTr(utfcodec);
   QTextCodec::setCodecForCStrings(utfcodec);
   QString sht = Numb_to_word(QString::number(z,'f',0));

   ui->label_7->setText(sht+"руб");
   qDebug() << sht;
   //общаяя сумма
   ui->label_3->setText(QString::number(z,'f',2));


}
void MainWindow::on_spinBox_14_valueChanged(const QString &arg1)
{
    ui->tableWidget->setItem(13,1,new QTableWidgetItem(arg1.toStdString().c_str()));

}
void MainWindow::on_spinBox_13_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(12,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_12_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(11,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_11_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(10,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_10_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(9,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_09_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(8,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_08_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(7,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_07_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(6,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_06_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(5,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_05_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(4,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_04_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(3,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_03_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(2,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_02_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(1,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}
void MainWindow::on_spinBox_01_valueChanged(const QString &arg1)
{
     ui->tableWidget->setItem(0,1,new QTableWidgetItem(arg1.toStdString().c_str()));
}


QString Numb_to_word(QString number)
{
    int numb = number.toInt();
    //массив, для определения разряда, в котором находимся(сотни,десятки,еденицы...)
    int osn[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    //массив оснований
    std::string basis[11][10]={
                {"","","","","","","","","",""},
                {"","один","два","три","четыре","пять","шесть","семь","восемь","девять"},
                {"","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто"},
                {"","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"},
                {"","одна","две","три","четыре","пять","шесть","семь","восемь","девять"},
                {"","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто"},
                {"","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"},
                {"","один","два","три","четыре","пять","шесть","семь","восемь","девять"},
                {"","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто"},
                {"","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"},
                {"","один","два","три ","четыре","пять","шесть","семь","восемь","девять"}};
    //массив окончаний
    std::string termination[10][10]={
                {"","","","тысяч","","","миллионов","","","миллиардов"},
                {"","","","тысяча","","","миллион","","","миллиард"},
                {"","","","тысячи","","","миллиона","","","миллиарда"},
                {"","","","тысячи","","","миллиона","","","миллиарда"},
                {"","","","тысячи","","","миллиона","","","миллиарда"},
                {"","","","тысяч","","","миллионов","","","миллиардов"},
                {"","","","тысяч","","","миллионов","","","миллиардов"},
                {"","","","тысяч","","","миллионов","","","миллиардов"},
                {"","","","тысяч","","","миллионов","","","миллиардов"},
                {"","","","тысяч","","","миллионов","","","миллиардов"}};
    std::string dec[10]={"десять","одиннадцать","двенадцать","тринадцать","четырнадцать","пятнадцать","шестнадцать","семнадцать","восемнадцать","девятнадцать"};
    std::string result;
    if (!numb){
           result="ноль ";
           return result.c_str();
            }
    int n1=numb;
    int cnt=0;
    //подсчет количесива цифр в числе
    while (numb){
                numb=numb/10;
                ++cnt;
            }
    int celoe=0;
    //перевод
    while (n1){
                if (!((cnt+1) % 3)){
                    if ((n1/osn[cnt])==1){
                            n1%=osn[cnt];
                            --cnt;
                            celoe=n1/osn[cnt];
                            n1%=osn[cnt];
                            result+=dec[celoe];
                        --cnt;
                        if (!(cnt % 3))
                            result+=" "+termination[0][cnt]+" ";
                    }
                    if (!cnt) break;
                }
                celoe=n1/osn[cnt];
                n1%=osn[cnt];
                result+=basis[cnt][celoe]+" ";
                --cnt;
                if (!(cnt % 3))
                    result+=termination[celoe][cnt]+" ";
            }

    return result.c_str();
}


