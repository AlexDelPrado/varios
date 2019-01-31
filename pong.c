#include <stdio.h>
#define V 20 //Vertical
#define H 60 //Horizontal

void inicio(char campo[V][H], int pelY, int pelX, int inicioJugador1, int finalJugador1, int inicioJugador2, int finalJugador2);
void cuadrado(char campo[V][H]);
void pelota(char [V][H], int pelY, int pelX);
void jugador1(char campo[V][H], int inicioJugador1, int finalJugador1);
void jugador2(char campo[V][H], int inicioJugador2, int finalJugador2);
void leerCampo(char campo[V][H]);
void gameLoop(char campo[V][H], int pelY, int pelX, int inicioJugador1, int finalJugador1, int inicioJugador2, int finalJugador2, int modPelX, int modPelY, int modJugador2);
void draw(char [V][H]);



int main(){

    //Variables posicion
    int pelX, pelY;
    int inicioJugador1, finalJugador1;
    int inicioJugador2, finalJugador2;
    int modPelX, modPelY, modJugador2; // Varibales modificacion
    
    char campo[V][H];
    
    // Inicializacion varibales posicion
    pelX = H / 2;
    pelY = V / 2;

    inicioJugador1 = 7;
    finalJugador1 = 12;

    inicioJugador2 = 7;
    finalJugador2 = 12;

    //Inicializacion varibles modificacion
    modPelX = -1;
    modPelY = -1;
    modJugador2 = -1;


    inicio(campo,pelY, pelX, inicioJugador1, finalJugador1, inicioJugador2, finalJugador2);
    gameLoop(campo,pelY, pelX, inicioJugador1, finalJugador1, inicioJugador2, finalJugador2,modPelX,modPelY,modJugador2);
    
    return 0;
}
void inicio(char campo[V][H], int pelY, int pelX, int inicioJugador1, int finalJugador1, int inicioJugador2, int finalJugador2){
    cuadrado(campo);
    pelota(campo, pelX, pelY);
    jugador1(campo, inicioJugador1, finalJugador1);
    jugador2(campo, inicioJugador2, finalJugador2);
}

void cuadrado(char campo[V][H]){
    int j, i;

	for (i = 0; i < V; i++) {
		for (j = 0; j < H; j++) {
			if (i == 0 || i == V - 1) {
				campo[i][j] = '-';
			}
			else if (j == 0 || j == H-1) {
				campo[i][j] = '|';
			}
			else {
				campo[i][j] = ' ';
			}
		}
	}
}
void pelota(char campo[V][H], int pelY, int pelX){
    campo[pelX][pelY] = 'O';
}

void jugador1(char campo[V][H], int inicioJugador1, int finalJugador1){
    int i,j;
    for(i = inicioJugador1; i <= finalJugador1; i++ ){
        for(j = 2; j <= 3; j++){
            campo[i][j] = 'S';
        }
    }
}
void jugador2(char campo[V][H], int inicioJugador2, int finalJugador2){
    int i,j;
    for(i = inicioJugador2; i <= finalJugador2; i++){
        for(j = H - 4  ; j <= H - 3 ; j++){
            campo[i][j] = 'W';
        }
    }
}

void leerCampo(char campo[V][H]){
    int i,j;

    for (i = 0; i < V; i++){
        for(j=0;j<H;j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}
void gameLoop(char campo[V][H], int pelY, int pelX, int inicioJugador1, int finalJugador1, int inicioJugador2, int finalJugador2, int modPelX, int modPelY, int modJugador2){
    int gol;
    gol = 0;
    
    do{
        draw(campo); // Dibujar en pantalla
        input(campo, &pelX, &pelY, &inicioJugador1, &finJugador1, &inicioJugador2, &finJugador2, &modPelX, &modPelY, &modJugador2, &gol); // Verificar y modificar posiciones
        upDate(); // Actualizar la matriz campo
        Sleep(10);

    } while (gol == 1);
}

void draw(char [V][H]){
    system ("cls");
    leerCampo(campo);

}
void input(char campo[V][H], int *pelX, int *pelY, int *inicioJugador1, int *finJugador1, int  *inicioJugador2, int *finJugador2, int *modPelX, int *modPelY, int *modJugador2, int *gol){
    //Verificacion
    if (pelY == 1 || pelY == V -2){
        *modPelY *= -1;
    }

    //Modificacion
}
void upDate(){

}