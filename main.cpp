// Trabalho M 1.2 - Structs e Templates.cpp 

#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;
    
struct Arma {
    int danoMaximo;
    int danoMinimo;
};

struct Jogador {
    string nome;
    int nivel;
    int vida;
    Arma arma;
};

struct Inimigo {
    string nome;
    int vida;
    Arma arma;
};

struct Fase {   
    string nomeFase;
    Inimigo inimigos;
};


template <typename T>
bool verificarMorte(T vida) {
    if (vida <= 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T1, typename T2>
int verificarAtaque(T1 atacante, T2 acometido) {
    srand(time(NULL));

    int dano = atacante.arma.danoMinimo;
    dano = dano + (rand() % (atacante.arma.danoMaximo - atacante.arma.danoMinimo));
    acometido.vida = acometido.vida - dano;
    cout << atacante.nome << " causou " << dano << " de dano no " << acometido.nome << endl;

    return acometido.vida;
}
void jogarFase(Jogador jogador, Inimigo inimigo[], int numInimigos) {
    bool verificadorJogador = false;
       for (int i = 1; i <= numInimigos and verificadorJogador == false; i++) {
           bool verificador2 = false;

           while (verificador2 == false and verificadorJogador == false) {
               inimigo[i].vida = verificarAtaque(jogador, inimigo[i]);
               verificador2 = verificarMorte(inimigo[i].vida);
               cout << "O " << inimigo[i].nome << " ficou com " << inimigo[i].vida << " de vida.\n\n";

               jogador.vida = verificarAtaque(inimigo[i], jogador);
               verificadorJogador = verificarMorte(jogador.vida);
               if(verificadorJogador == true){
                 break;
               }
               cout << "O " << jogador.nome << " ficou com " << jogador.vida << " de vida.\n\n";
           }
           cout << "\t" << jogador.nome << " matou " << inimigo[i].nome << "\n\n";
       }
       
    if (verificadorJogador == false){
        cout << "\tParabens! Voce ganhou o jogo! " << endl;
    }
    else {
       cout << jogador.nome << " Morreu! Voce perdeu o jogo! " << endl;
    }
}

void oCondado() {
    srand(time(NULL));
    int numInimigos = 5;
    Inimigo inimigo[6];
    Jogador jogador;

    inimigo[1].nome = "Orc";
    inimigo[2].nome = "outro Orc";
    inimigo[3].nome = "Mestre Orc";
    inimigo[4].nome = "Doutor Orc";
    inimigo[5].nome = "Chefe Orc";

    for (int i = 1; i <= 5; i++) {
        inimigo[i].vida = 100 + (rand() % 100);
        inimigo[i].arma.danoMinimo = 40;
        inimigo[i].arma.danoMaximo = inimigo[i].arma.danoMinimo + (rand() % 100);
    }

    jogador.nome = "SerjaoBerrantero";
    jogador.vida = 1000;
    jogador.arma.danoMinimo = 50;
    jogador.arma.danoMaximo = jogador.arma.danoMinimo + (rand() % 100);

    cout << "\tEntrando no territorio da Terra Media\t " << endl;
    cout << "\n\t      Primeiro Local - O Condado \t\n" << endl;
    
    jogarFase(jogador, inimigo, numInimigos);
}


int main()
{
    oCondado();
    return(0);
}
