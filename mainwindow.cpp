#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>
#include <QDebug>
#include <map>
#include <QPushButton>
#include <QColorDialog>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
string p = "/home/" + string(getenv("USER")) + "/.local/share/dualsensectl/";
string exe = "/home/" + string(getenv("USER")) + "/.local/share/dualsensectl/dualsensectl";

string space= " ";
const char* cspace= space.c_str();

std::map<std::string, int> colors = {};
int r = 0;
int g = 0;
int b = 255;

class QColorDialogTester : public QWidget
{
public:
  std::map<std::string,int> onColor()
  {
    QColor color = QColorDialog::getColor(Qt::red, this );
    if( color.isValid() )
    {
      int red   = color.red();
      int green = color.green();
      int blue  = color.blue();

      int COLOR_CHOSEN[3]={red,green,blue};

      qDebug() << "Color Choosen" << COLOR_CHOSEN[0] << ", " << COLOR_CHOSEN[1] << ", " << COLOR_CHOSEN[2] ;
      colors = {
          { "r",  COLOR_CHOSEN[0] },
          { "g",  COLOR_CHOSEN[1] },
          { "b",  COLOR_CHOSEN[2] }
      };

      r = colors.at("r");
      g = colors.at("g");
      b = colors.at("b");
    }
    return colors;
  }

};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    string d;
    d.append("rm -f ");
    d.append(p);
    d.append("batterystat ; ");
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("battery >> ");
    d.append(p);
    d.append("batterystat");
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());

    /* Battery Status */

    ifstream file;
    string bfile;
    string per;
    string stat;
    bfile.append(p);
    bfile.append("batterystat");
    file.open(bfile);
    file >> per ;
    stat.append("<html><head/><body><p align='center'><span style='font-size:18pt;'>");
    stat.append(per);
    stat.append("%</span></p></body></html>");
    qDebug() << stat.c_str();

    ui->battery->setText(stat.c_str());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_released()
{
    qDebug() << "Opening Color Picker";
    QColorDialogTester picker;
    picker.onColor();
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("lightbar");
    d.append(" ");
    d.append(to_string(r));
    d.append(" ");
    d.append(to_string(g));
    d.append(" ");
    d.append(to_string(b));
    d.append(" ");
    d.append("255");
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_B0_clicked()
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("player-leds");
    d.append(" ");
    d.append(to_string(0));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_B1_clicked()
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("player-leds");
    d.append(" ");
    d.append(to_string(1));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_B2_clicked()
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("player-leds");
    d.append(" ");
    d.append(to_string(2));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_B3_clicked()
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("player-leds");
    d.append(" ");
    d.append(to_string(3));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_B4_clicked()
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("player-leds");
    d.append(" ");
    d.append(to_string(4));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_B5_clicked()
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("player-leds");
    d.append(" ");
    d.append(to_string(5));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_brightness_valueChanged(int value)
{
    string d;
    d.append(exe);
    d.append(cspace);
    d.append(" ");
    d.append("lightbar");
    d.append(" ");
    d.append(to_string(r));
    d.append(" ");
    d.append(to_string(g));
    d.append(" ");
    d.append(to_string(b));
    d.append(" ");
    d.append(to_string(value));
    qDebug() << "running this command" << d.c_str();
    system(d.c_str());
}

void MainWindow::on_pushButton_clicked()
{

}
