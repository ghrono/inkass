#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_spinBox_01_valueChanged(const QString &arg1);
    void on_spinBox_02_valueChanged(const QString &arg1);
    void on_spinBox_03_valueChanged(const QString &arg1);
    void on_spinBox_04_valueChanged(const QString &arg1);
    void on_spinBox_05_valueChanged(const QString &arg1);
    void on_spinBox_06_valueChanged(const QString &arg1);
    void on_spinBox_07_valueChanged(const QString &arg1);
    void on_spinBox_08_valueChanged(const QString &arg1);
    void on_spinBox_09_valueChanged(const QString &arg1);
    void on_spinBox_10_valueChanged(const QString &arg1);
    void on_spinBox_11_valueChanged(const QString &arg1);
    void on_spinBox_12_valueChanged(const QString &arg1);
    void on_spinBox_13_valueChanged(const QString &arg1);
    void on_spinBox_14_valueChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
