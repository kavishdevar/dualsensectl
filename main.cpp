#include "mainwindow.h"

#include <QApplication>

#include <QDebug>

#include <bits/stdc++.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <QLabel>
using namespace std;

const char* name = getenv("USER");

string PATH = "/home/" + string(name) + "/.local/share/dualsensectl" ;
const char* Pchar = PATH.c_str();
const char* n = "wget -O ";
const char* m = "/main.c https://raw.githubusercontent.com/nowrep/dualsensectl/main/main.c" ;
const char* o = "/crc32.h https://raw.githubusercontent.com/nowrep/dualsensectl/main/crc32.h" ;
const char* f = " 2> /dev/null";

string f1= PATH+"/main.c";
string f2= PATH+"/crc32.h";

string cmd1 = string(n) + string(Pchar) + string(m) + string(f);

string cmd2 = string(n) + string(Pchar) + string(o) + string(f);

string cmd3 = string("cd ") + PATH + string("; gcc -o dualsensectl -DDUALSENSECTL_VERSION=\"0.1\" -Wall -Wextra -pedantic -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include  -I/usr/include/hidapi  -O2 -s -DNDEBUG -L/usr/lib/x86_64-linux-gnu -L/usr/lib/x86_64-linux-gnu  main.c -ldbus-1  -lhidapi-hidraw ") ;

string exec = PATH + string("/dualsensectl");

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

inline bool exists_test0 (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

inline bool exists_test1 (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

inline bool exists_test2 (const std::string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}

inline bool exists_test3 (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char *argv[])
{

    qDebug() << "This is the path -> " << PATH.c_str();

    if ( is_file_exist(exec.c_str()) or exists_test0(exec.c_str()) or exists_test1(exec.c_str()) or exists_test2(exec.c_str()) or exists_test3(exec.c_str())){
        qDebug() << "File exists!";
    }
    else {
        qDebug() << "These are the commands :: ";
        qDebug() << cmd1.c_str();
        qDebug() << cmd2.c_str();
        qDebug() << cmd3.c_str();

        qDebug() << "Creating directory for storing exec.";

        mkdir(PATH.c_str(),0777);

        qDebug() << "Getting main.c";

        system(cmd1.c_str());

        qDebug() << "Getting crc32.h";

        system(cmd2.c_str());

        qDebug() << "Compiling";

        system(cmd3.c_str());
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
