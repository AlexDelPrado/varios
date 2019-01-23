#include <stdio.h>
#define Y 20 //vertical
#define X 80 //horizontal

void inicio(char campo[Y][X], int pelX, int pelY, int iniJugador, int finJugador, int iniPc, int finPc);
void borde(char campo[Y][X]);
void raqJug(char campo[Y][X], int iniJugador, int finJugador);
void raqPc(char campo[Y][X], int iniPc, int finPc);
void pelota(char campo[Y][X], int pelX, int pelY);
void leerCampo(char campo[Y][X]);

int main() {
	
	int pelX, pelY, iniJugador, finJugador, iniPc, finPc;
	char campo[Y][X];

	pelX = 40;
	pelY = 10;

	iniJugador = 8;
	finJugador = 12;

	iniPc = 8;
	finPc = 12;

	inicio(campo, pelX,pelY,iniJugador,finJugador, iniPc,finPc);
	leerCampo(campo);
	system("pause");
	return 0;
}

void inicio(char campo[Y][X], int pelX, int pelY, int iniJugador, int finJugador, int iniPc, int finPc) {
	borde(campo);
	raqJug(campo, iniJugador, finJugador);
	raqPc(campo, iniPc, finPc);
	pelota(campo, pelX, pelY);
}

void borde(char campo[Y][X]) {
	int j, i;

	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			if (i == 0 || i == Y - 1) {
				campo[i][j] = '-';
			}
			else if (j == 0 || j == X-1) {
				campo[i][j] = '|';
			}
			else {
				campo[i][j] = ' ';
			}
		}
	}
}
void raqJug(char campo[Y][X], int iniJugador, int finJugador) {
	int i, j;

	for (i = iniJugador; i <= finJugador; i++) {
		for (j = 2; j <= 3; j++) {
			campo[i][j] = 'x';
		}
	}
}
void raqPc(char campo[Y][X],int iniPc,int finPc) {
	int i, j;

	for (i = iniPc; i <= finPc; i++) {
		for (j = X - 4; j <= X - 3; j++) {
			campo[i][j] = 'x';
		}
	}

}
void pelota(char campo[Y][X], int pelX, int pelY) {
	campo[pelY][pelX] = '0';
}
void leerCampo(char campo[Y][X]) {
	int i, j;

	for (i = 0; i < Y; i++) {
		for (j = 0; j < X; j++) {
			printf("%c", campo[i][j]);
		}
		printf("\n");
	}
}
