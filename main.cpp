
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define ALTO 20
#define ANCHO 70


void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

struct coord{
    int x;
    int y;
};

void limites(){
    for(int i=0; i<ANCHO; i++){
        gotoxy(i,0);printf("%c",205);
        gotoxy(i,ALTO);printf("%c",205);
    }
    for(int i=0; i<ALTO; i++){
        gotoxy(0,i);printf("%c",186);
        gotoxy(ANCHO,i);printf("%c",186);
    }
}

void red(){
    for(int i=1;i<ALTO;i++){
        gotoxy(ANCHO/2,i),printf("%c",186);
    }
}

void player(coord pos, int c){
    switch(c)
    {
        case 0:
            gotoxy(pos.x,pos.y-1);printf("%c",219);
            gotoxy(pos.x,pos.y  );printf("%c",219);
            gotoxy(pos.x,pos.y+1);printf("%c",219);
            break;
        case 1:
            gotoxy(pos.x,pos.y-1);printf(" ");
            gotoxy(pos.x,pos.y  );printf(" ");
            gotoxy(pos.x,pos.y+1),printf(" ");
            break;
    }

}

void pelota(coord &pel, int c){
    switch(c){
            case 0:
                gotoxy(pel.x,pel.y);printf("%c",184);
                break;
            case 1:
                gotoxy(pel.x,pel.y);printf(" ");
                break;
    }
}

void move(coord &pos){
    if(kbhit()){
        coord copy = pos;
        player(pos,1);
        char tecla = getch();
        if(tecla == 'w')copy.y--;
        if(tecla == 's')copy.y++;
        if(copy.y > 2 && copy.y < ALTO-2) pos=copy;
        player(pos,0);
    }
}

void mov_ene(coord &ene, coord pel){
    if(pel.x > (ANCHO/2+10)){
        player(ene,1);
        if(pel.y > ene.y && ene.y < ALTO-2) ene.y++;
        if(pel.y < ene.y && ene.y >2) ene.y--;
        player(ene,0);
    }
}
void marcador(coord mar){
    gotoxy(ANCHO+7,1);printf("Marcador");
    gotoxy(ANCHO+2,3);printf("Jugador");
    gotoxy(ANCHO+5,5);printf("%d", mar.x);
    gotoxy(ANCHO+12,3);printf("Oponente");
    gotoxy(ANCHO+16,5);printf("%d", mar.y);
}
void reset(coord &mar, coord &pel, bool mov){
    pelota(pel,1);
    gotoxy(ANCHO+5,5);printf("  ");
    gotoxy(ANCHO+16,5);printf("  ");
    mov=false;
    mar = {0,0};
    pel = {ANCHO/2,ALTO/2};
    pelota(pel,0);
    marcador(mar);
}

void inicio(coord &aum, coord pel, bool &mov, coord &mar){

    mov=false;
    if(pel.x > ANCHO/2+10) mar.x++;
    else if(pel.x < ANCHO/2-10){mar.y++;}
    pelota(pel,1);
    pel = {ANCHO/2,ALTO/2};
    aum.y = -aum.y;
    marcador(mar);
}

void mover_pel(coord &pel, coord &aum, bool mov){
    coord copy = pel;
    pelota(pel,1);
    if(mov){
        copy.x += aum.x;
        copy.y += aum.y;
    }
    if(copy.y > ALTO-1 || copy.y < 1){
        copy=pel;
        aum.y = -aum.y;
    }
    pel = copy;
    pelota(pel,0);

}

void choque(coord pos, coord pel, coord &aum, coord &ene){
    if(pos.x == pel.x-1){
        if(pel.y < pos.y + 2 && pel.y > pos.y-2) aum.x = 1;
    }
    else if(ene.x == pel.x+1){
        if(pel.y < ene.y + 2 && pel.y > ene.y-2) aum.x = -1;
    }

}

void update(coord &pel, coord &aum, bool &mov, coord &mar, bool &puntoMarcado){
    if(kbhit()){
        char tecla = getch();
        if(tecla == 'e') mov=true;
        if(tecla == 'q')reset(mar,pel,mov);
    }
    if (!puntoMarcado) {

        if (pel.x > ANCHO - 3) {
            mar.x++;
            puntoMarcado = true;
            inicio(aum, pel, mov, mar);
        }
         else if (pel.x < 3) {
            mar.y++;
            puntoMarcado = true;
            inicio(aum, pel, mov, mar);
        }
    }


    if (pel.x == ANCHO / 2 && pel.y == ALTO / 2) {
        puntoMarcado = false;
    }
}


main(){
    coord pos = {10, ALTO/2};
    coord pel = {ANCHO/2, ALTO/2};
    coord aum = {1,1};
    coord ene = {ANCHO-10, ALTO/2};
    coord mar = {0,0};

    int u=0;
    bool puntoMarcado= false;
    bool game=true;
    bool mov=false;

    limites();
    red();
    player(pos,0);
    player(ene,0);
    pelota(pel,0);
    marcador(mar);

    float fps = 50.0f;
    float dt = 1.0f/fps;
    float acumulador = 0.0f;

    clock_t inicio = clock();
    while(game){
        clock_t final = clock();
        acumulador += float(final-inicio)/CLOCKS_PER_SEC;
        inicio = final;

        if(acumulador <= 0.2f) acumulador = 2.0f;
        while(acumulador >= dt){
            move(pos);
            update(pel,aum,mov,mar,puntoMarcado);
            acumulador -= dt;
        }
        u++;
        if(u==30){
            mover_pel(pel,aum,mov);
            u=0;
        }
        mov_ene(ene,pel);
        choque(pos,pel,aum,ene);
        if(pel.x == ANCHO/2-1 || pel.x == ANCHO/2+1) red();

    }
    return 0;
}


