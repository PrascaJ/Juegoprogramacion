#include <windows.h>
#include <conio.h>
#include <studio.h>
#include <time.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27
#define ENTER 13

int cuerpo{200}[2];
int  x = 10, y = 12;
int xc = 30, yc = 15;
int tam=3;
int n=1;
char tecla;
int dir = 3;
int score = 0;
int velocidad=100, h=1:
int pos = 1;

void gotoxy(int x, int y){
  HANDLE hCon;
  COORD dwPos; 
  dwPos.X = x;
  dwPos.Y = y;
  hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hCon,dwPos);

char inicio[50][100] =
{
"                           ", 
" BIENVENIDOS SEAN TODOS!!! ",
"                           ",        
"            S S            ",
"           S   S           ",
"          S     S          ",
"         S       S         ",
"        S         S        ",
"       S           S       ",
"      S             S      ",
"       S           S       ",
"        S         S        ",
"         S       S         ",
"          S     S          ",
"           S   S           ",
"            S S            ",
"             S             ",
"            S S            ",
"           S   S           ",
"          S     S          ",
"         S       S         ",
"      S S         S S      ",
"     S               S     ",
"    S                 S    ",
"   S                   S   ",
"    S                 S    ",
"     S               S     ",
"      S S         S S      ",
"         S       S         ",
"          S     S          ",
"           S   S           ",
"            S S            ",
"             S             ",
};

void menu_inicial () {
  for(int i = 0 ; i < 17 ; i++) {
    for(int j = 0 ; j < 71 ; j++) {
      if(inicio[i] [j] == 'A') {
        gotoxy(j+5,i+5); printf("↔");
      }
    }
  }

  tecla = getch ();

    for(int i = 0 ; i < 17 ; i++) {
    for(int j = 0 ; j < 71 ; j++) {
      if(inicio[i] [j] == 'A') {
        gotoxy(j+5,i+5); printf("↔");
      }
    }
  }
}
  void pintar()
{

  for(int i = 2; i < 78; i++){
    gotoxy (i, 3); printf ("↔", 205);
    gotoxy (i, 23); printf ("↔", 205);
  }
 for(int v = 4; v < 23; v++){
    gotoxy (2, v); printf ("↑", 186);
    gotoxy (77, v); printf ("↑", 186);
  }
  
  gotoxy (2, 3); printf ("↨↔", 201);
  gotoxy (2, 23); printf ("↨↔", 200);
  gotoxy (77, 3); printf ("↨↔", 187);
  gotoxy (77, 23); printf ("↨↔", 188);
  
}

void guardar_posicion(){
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if(n==tam)n=1;
}

void dibujar_cuerpo(){
	for(int i=1;i<tam;i++){
		gotoxy(cuerpo[i][0],cuerpo[i][1]);printf("%c",2);
	}
}

void borrar_cuerpo(){
		gotoxy(cuerpo[n][0],cuerpo[n][1]);printf(" ");
	
}
void teclear(){
	if(kbhit()){
		tecla=getch();
		switch(tecla){
			case ARRIBA:
				if(dir!=2)
				   dir=1;
				   break;
		    case ABAJO:
		    	if(dir!=1)
			       dir=2;
				   break;
			case DERECHA:
				if(dir!=4)
				   dir=3;
				   break;
			case IZQUIERDA:
				if(dir!=3)
				   dir=4;
				   break;	   	
		}
	}
	
}

void cambiar_velocidad(){
	if(score==h*20){
		velocidad-=10;
		h++;
	}
}

void comida(){
	if(x==xc&&y==yc){
		xc=(rand()%73)+4;
		yc=(rand()%19)+4;
		tam++;
		score+=10;
		gotoxy(xc,yc);printf("%c",4);
		
	}
	
}

bool game_over(){
	if(y==3||y==23||x==2||x==77)return false;
	for(int j=tam-1;j>0;j--){
		if(cuerpo[j][0]==x&&cuerpo[j][1]==y)
		return false;
	}
	return true;
}

void puntos(){
	gotoxy(3,1);printf("score 00%d",score);
}

bool win(){
	if(w==score)return false;
	return true;
		
	}


        

void game(){
	while(tecla!=ESC&&game_over()&& win()){
	puntos();
	borrar_cuerpo();
	guardar_posicion();
	dibujar_cuerpo();
	comida();
	
	teclear();
	teclear();

	if(dir==1)y--;
	if(dir==2)y++;
	if(dir==3)x++;
	if(dir==4)x--;
	Sleep(velocidad);
	
if ( !game_over()){
	MessageBox(NULL,"HAS PERDIDO","  GAME OVER", MB_OK);
	system("cls");
}
if ( !win()){
	MessageBox(NULL,"HAS GANADO","  WIN", MB_OK);
	system("cls");
	
}
}
}	

int main(){
	titulo();
	pintar();
	gotoxy(xc,yc);printf("%c",4);
	game();
	
	system("pause>NULL");
	return 0;
}
