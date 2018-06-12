#ifndef ARREGLOLEX_H
#define ARREGLOLEX_H

#include <QDebug>;
#include <iostream>;

using namespace std;


class ArregloLex{


public:

    //Numero de Dimensiones
    int k;

    //Limites Inferiores
    int *n;

    //Limites Superiores
    int *m;

    //Magnitud de cada dimension
    int *MAGS;

    //Direccion del Primer Elemento
    int *alfa;

    //Numero Maximo de Elementos que puede almacenar el Arreglo
    int MaxSt;

    //Constructor
    ArregloLex(int k,int *n,int *m){

        //Actualizando k
        this->k = k;

        //Inicializando el Arreglo de Magnitudes
        this->MAGS = new int[k];

        //Dimensionando los limites
        this->n = new int[k];
        this->m = new int[k];

        //Cargando los valores
        int CNC = 0;
        int Mag_Dim = 0;
        this->MaxSt = 1;

        while(CNC < k){
            //Limites Inferiores
            this->n[CNC] = n[CNC];

            //Limites Superiores
            this->m[CNC] = m[CNC];

            //Magnitud segun los limites
            Mag_Dim = (m[CNC] - n[CNC]);

            //Numero Maximo de Elementos que puede almacenar el Arreglo
            MaxSt *= Mag_Dim;

            //Carando las Magnitudes
            this->MAGS[CNC] = Mag_Dim;

            CNC++;
        }

        //Dimensionando Alfa
        this->alfa = new int[MaxSt];

        //
    }


    //Obtener un Elemento donde i[] contiene las Coordenadas de ese Elemento
    int &operator[](int i[]){

        int Mt = 1;
        int Ps = 0;

        int Lc = 0;

        int CNT_DIR = 0;
        while(CNT_DIR < (this->k)){

            if(CNT_DIR > 2){
                Mt *= this->MAGS[CNT_DIR-1];
                Ps = i[CNT_DIR];
            }

            if(CNT_DIR == 2){
                Mt = MAGS[0] * MAGS[1];
                Ps = i[2];
            }

            if(CNT_DIR == 1){
                Mt = this->MAGS[1];
                Ps = i[0];
            }

            if(CNT_DIR == 0){
                Mt = 1;
                Ps = i[1];
            }

            Lc += (Ps*Mt);

            cout << "LEXICO: " << Lc << "\n";
            CNT_DIR++;
        }

        if(Lc < MaxSt){
            //Aqui retorno la localizacion Lc
            return alfa[Lc];
        }
        else{
            //El indice fuera de rango

        }
    }
};

#endif // ARREGLOLEX_H
