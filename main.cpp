#include "mainwindow.h"
#include <QApplication>
#include "arreglolex.h"





int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    int * LInf = new int[5];
    int * LSup = new int[5];

    LInf[0] = 0;
    LInf[1] = 0;
    LInf[2] = 0;
    LInf[3] = 0;
    LInf[4] = 0;

    LSup[0] = 3;
    LSup[1] = 2;
    LSup[2] = 7;
    LSup[3] = 4;
    LSup[4] = 5;

    int * Dirs = new int[5];

    Dirs[0] = 3;
    Dirs[1] = 4;
    Dirs[2] = 9;
    Dirs[3] = 6;
    Dirs[4] = 7;


    ArregloLex MRM(5,LInf,LSup);
    int a = MRM[Dirs];

    //return a.exec();marco  Tprobalo con un test tuyo abr si da lo mismo PSAME TU CODIGO PS...
    //pero me refiero a solo llenar los vectores con los mismos datos PASAME TUS VECTORES va

    return 0;
}
