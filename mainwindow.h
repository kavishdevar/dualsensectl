#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_button_released();
    void on_B0_clicked();
    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();
    void on_brightness_valueChanged(int value);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
