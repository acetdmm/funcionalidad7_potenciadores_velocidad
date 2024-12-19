#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ANCHO 20
#define ALTO 10

// Variables para el primer juego (nave contra enemigos)
char mapa[ALTO][ANCHO];
int posX = ANCHO / 2, posY = ALTO - 2; // Posición inicial de la nave
vector<pair<int, int>> enemigos; // Lista de enemigos

// Variables para el segundo juego (nave y potenciadores)
const int anchoPantalla = 20;
const int altoPantalla = 20;
int velocidad = 1;
vector<int> potenciadoresX, potenciadoresY;

void inicializarMapa() {
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            if (i == 0 || i == ALTO - 1 || j == 0 || j == ANCHO - 1) {
                mapa[i][j] = '#'; // Bordes del mapa
            } else {
                mapa[i][j] = ' ';
            }
        }
    }
}

void dibujarMapa() {
    mapa[posY][posX] = '>'; // Dibuja la nave
    for (int i = 0; i < enemigos.size(); i++) {
        mapa[enemigos[i].second][enemigos[i].first] = 'E'; // Dibuja enemigos
    }
    // Dibujar los elementos del segundo juego
    for (int i = 0; i < potenciadoresX.size(); i++) {
        mapa[potenciadoresY[i]][potenciadoresX[i]] = 'P'; // Dibuja potenciadores
    }

    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

void moverNave(char tecla) {
    mapa[posY][posX] = ' '; // Borra la nave en su posición actual
    if (tecla == 'a' && posX > 1) posX--; // Mueve la nave a la izquierda
    if (tecla == 'd' && posX < ANCHO - 2) posX++; // Mueve la nave a la derecha
}

void moverEnemigos() {
    for (int i = 0; i < enemigos.size(); i++) {
        mapa[enemigos[i].second][enemigos[i].first] = ' '; // Borra al enemigo
        enemigos[i].second++; // Mueve al enemigo hacia abajo
        if (enemigos[i].second == ALTO - 1) {
            enemigos.erase(enemigos.begin() + i); // Elimina el enemigo si llega al final
            i--;
        }
    }
}

void generarEnemigo() {
    enemigos.push_back({rand() % ANCHO, 1}); // Genera un enemigo en una posición aleatoria
}

void generarPotenciador() {
    potenciadoresX.push_back(rand() % ANCHO);
    potenciadoresY.push_back(rand() % (ALTO / 2));
}

void verificarPotenciadores() {
    for (int p = 0; p < potenciadoresX.size(); p++) {
        if (posX == potenciadoresX[p] && posY == potenciadoresY[p]) {
            velocidad++; // Aumenta la velocidad al recoger un potenciador
            potenciadoresX.erase(potenciadoresX.begin() + p);
            potenciadoresY.erase(potenciadoresY.begin() + p);
            return;
        }
    }
}

void disparar() {
    int posBalaY = posY - 1;
    int posBalaX = posX;
    while (posBalaY > 0) {
        if (mapa[posBalaY][posBalaX] == 'E') {
            mapa[posBalaY][posBalaX] = ' '; // Destruye al enemigo
            for (int i = 0; i < enemigos.size(); i++) {
                if (enemigos[i].first == posBalaX && enemigos[i].second == posBalaY) {
                    enemigos.erase(enemigos.begin() + i);
                    break;
                }
            }
            return;
        }
        posBalaY--;
        Sleep(50);
    }
}

int main() {
    srand(time(0)); // Para generar números aleatorios
    char tecla;
    int contador = 0;

    inicializarMapa(); // Inicializa el mapa para el primer juego
    enemigos.push_back({5, 1}); // Agrega un enemigo inicial
    enemigos.push_back({10, 1}); // Agrega otro enemigo inicial

    do {
        system("cls"); // Limpia la pantalla
        dibujarMapa(); // Dibuja el mapa

        if (_kbhit()) {
            tecla = _getch();
            if (tecla == 'x') break; // Si se presiona 'x', termina el juego
            if (tecla == 'a' || tecla == 'd') {
                moverNave(tecla); // Mueve la nave
            }
            if (tecla == ' ') {
                disparar(); // Dispara la nave
            }
        }

        if (contador % 10 == 0) generarEnemigo(); // Genera enemigos periódicamente
        if (contador % 30 == 0) generarPotenciador(); // Genera potenciadores periódicamente
        moverEnemigos(); // Mueve los enemigos
        verificarPotenciadores(); // Verifica si se recogieron potenciadores

        Sleep(100); // Controla la velocidad del juego
        contador++;
    } while (true);

    return 0;
}
