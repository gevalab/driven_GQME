#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "constant.h"

int input(class Hamiltonian & Hami_sim, class timer & time_sim, class state & stat_sim){
    cout << "input start" << endl;
    ifstream infile;
    infile.open("input.txt",ios::in);
    char name[20];
    int flag = 1;
    do{
        infile >> name;
        if(strcmp(name,"w")==0){
            infile >> Hamiltonian::w;
            cout << "w: " << Hamiltonian::w << endl;
        }else if(strcmp(name,"w01")==0){
            infile >> Hamiltonian::w01;
            cout << "w01:   " << Hamiltonian::w01 << endl;
        }else if(strcmp(name,"epsilon")==0){
            infile >> Hamiltonian::epsilon;
            cout << "epsilon:   " << Hamiltonian::epsilon << endl;
        }else if(strcmp(name,"Lambda")==0){
            infile >> Hamiltonian::Lambda;
            cout << "Lambda:    " << Hamiltonian::Lambda << endl;
        }else if(strcmp(name,"N")==0){
            infile >> Hamiltonian::N;
            cout << "N: " << Hamiltonian::N << endl;;
        }else if(strcmp(name,"wc")==0){
            infile >> Hamiltonian::wc;
            cout << "wc:    " << Hamiltonian::wc << endl;
        }else if(strcmp(name,"eta")==0){
            infile >> Hamiltonian::eta;
            cout << "eta:   " << Hamiltonian::eta << endl;
        }else{flag=0;}
    }while(flag);
    
    flag=1;
    do{
        infile >> name;
        if(strcmp(name,"T")==0){
            infile >> time_sim.T;
            cout << "T: " << time_sim.T << endl;
        }else if(strcmp(name,"dt")==0){
            infile >> time_sim.dt;
            cout << "dt:    " << time_sim.dt << endl;
        }else{flag=0;}
    }while(flag);

    flag=1;
    do{
        infile >> name;
        if(strcmp(name,"sigma")==0){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    infile >> stat_sim.sigma(i,j);
                }
            }
            stat_sim.sigma.print("sigma:  ");
        }else{flag=0;}
    }while(flag);

    infile.close();
    cout << "input over" << endl;
    return 0;
}

#endif