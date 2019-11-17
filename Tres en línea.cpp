#include <iostream>
using namespace std;

#define n 3
int turno=1;
int b=0;

string tablero[n][n];

void iniciarTablero();
void imprimirTablero();
void pedirPosicion();
void asignarValor(string valor, int p);
bool revisarResultado();
bool revisarEmpate();

int main(){
    iniciarTablero();
    imprimirTablero();
    pedirPosicion();
    return 0;
}

void iniciarTablero(){
    int a=0;
    for (int i=0; i<=n-1; i++){
        for (int j=0; j<=n-1; j++){
            tablero[i][j]=to_string(a);
            a++;
        }
    }
}

void imprimirTablero(){
    for (int i=0; i<=n-1; i++){
        for (int j=0; j<=n-1; j++){
            cout<<tablero[i][j]<<"|";
        }
        cout<<"\n------\n";
    }
}

void pedirPosicion(){
    int posicion=0;
    cout<<"Turno "<<turno<<endl<<"Seleccione una posición: ";
    cin>>posicion;
    if(posicion<=9&&posicion>=0){
        if(turno%2!=0){
            asignarValor("X", posicion);
        }else{
            asignarValor("O", posicion);
        }
    }else{
        cout<<"Por favor, ingrese una opción válida.\n";
        pedirPosicion();
    }
}

void asignarValor(string valor, int p){
    switch(p){
        case 0:
            if(tablero[0][0]!="X"&&tablero[0][0]!="O")tablero[0][0]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 1:
            if(tablero[0][1]!="X"&&tablero[0][1]!="O")tablero[0][1]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 2:
            if(tablero[0][2]!="X"&&tablero[0][2]!="O")tablero[0][2]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 3:
            if(tablero[0][3]!="X"&&tablero[0][3]!="O")tablero[1][0]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 4:
            if(tablero[1][1]!="X"&&tablero[1][1]!="O")tablero[1][1]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 5:
            if(tablero[1][2]!="X"&&tablero[1][2]!="O")tablero[1][2]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 6:
            if(tablero[2][0]!="X"&&tablero[2][0]!="O")tablero[2][0]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 7:
            if(tablero[2][1]!="X"&&tablero[2][1]!="O")tablero[2][1]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
        case 8:
            if(tablero[2][2]!="X"&&tablero[2][2]!="O")tablero[2][2]=valor;
            else{ cout<<"Esa posición se encuentra ocupada.\n";
                pedirPosicion();
            }
        break;
    }
    turno++;
    imprimirTablero();
    if(revisarResultado()==true){
        if(turno%2!=0){
            cout<<"Jugador 1 (X) gana.";
        }else{
            cout<<"Jugador 2 (O) gana.";
        }
    }else{
        if(revisarEmpate()==true){
            cout<<"Empate.\n";
            main();
        }else{
            pedirPosicion();
        }
    }
}

bool revisarResultado(){
    if(tablero[0][0]==tablero[1][1]&&tablero[0][0]==tablero[2][2])return true;
    else return false;
    if(tablero[0][2]==tablero[1][1]&&tablero[0][2]==tablero[2][0])return true;
    else return false;
    if(tablero[0][0]==tablero[0][1]&&tablero[0][0]==tablero[0][2])return true;
    else return false;
    if(tablero[1][0]==tablero[1][1]&&tablero[1][0]==tablero[1][2])return true;
    else return false;
    if(tablero[2][0]==tablero[2][1]&&tablero[2][0]==tablero[2][2])return true;
    else return false;
    if(tablero[0][0]==tablero[1][0]&&tablero[0][0]==tablero[2][0])return true;
    else return false;
    if(tablero[0][1]==tablero[1][1]&&tablero[0][1]==tablero[2][1])return true;
    else return false;
    if(tablero[0][2]==tablero[1][2]&&tablero[0][2]==tablero[2][2])return true;
    else return false;
}

bool revisarEmpate(){
    for (int i=0; i<=n-1; i++){
        for (int j=0; j<=n-1; j++){
            if(tablero[i][j]!="X"&&tablero[i][j]!="O"){
                b++;
            }
        }
    }
    if (b==9)return true;
    else return false;
}