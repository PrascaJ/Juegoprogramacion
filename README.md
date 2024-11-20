# PING PONG
T00065013

Juego de PING PONG elaborado con C++ en Code::Blocks.
Consiste en un juego clasico de PING PONG donde el jugador que compite contra la maquina debe evitar que la pelota pase de su lado, esto moviendo una barra como representacion de una raqueta.


CONTROLES:

Jugador 1 (usuario):

w: Subir la barra.

s: Bajar la barra.

Inicio y pausa:

e: Inicia  el movimiento de la pelota.

q: Reinicia el juego y la puntuación.


(Actualmente este codigo solo permite un unico jugador y unico modo de dificultad, pero la forma del codigo permitiria a futuro la evolucion de este para agregar diferentes dificultades y un modo de dos jugaodressi alguna persona lo desease.)


La librerias empleadas en el codigo son:

Windows.h: Para manipular la posición del cursor en la consola.

conio.h: Para detectar entradas del teclado sin bloquear la ejecución.

time.h: Para medir el tiempo y controlar la velocidad de actualización del juego.

# Atributos y Métodos de los Elementos

#1. Jugador y Oponente: 
Ambos son barras verticales que comparten lógica de movimiento.

Atributos:
coord pos: La posición x y y de la barra.

Métodos:

player(coord pos, int c): Dibuja la barra en la pantalla (c=0) o la elimina (c=1).

move(coord &pos): Permite al jugador mover su barra hacia arriba o abajo mediante las teclas W y S.

mov_ene(coord &ene, coord pel): Controla el movimiento del oponente (IA), haciendo que siga la posición de la pelota.

#2. Pelota:
Es el elemento que se mueve y colisiona con las barras y los bordes del campo.

Atributos:

coord pel: La posición actual de la pelota (x y y).

coord aum: Dirección de movimiento de la pelota (x e y, que pueden ser 1 o -1).

Métodos:

pelota(coord &pel, int c): Dibuja la pelota en la pantalla (c=0) o la borra (c=1).

#3. Marcador:
El marcador es un elemento visual que muestra los puntos del jugador y del oponente.

Atributos:

coord mar: Contiene el puntaje del jugador (mar.x) y del oponente (mar.y).

Métodos:

marcador(coord mar): Muestra el puntaje actual en el lado derecho de la pantalla.

mover_pel(coord &pel, coord &aum, bool mov): Actualiza la posición de la pelota dependiendo de su dirección y si el juego está en movimiento.

choque(coord pos, coord pel, coord &aum, coord &ene): Detecta si la pelota choca con las barras del jugador u oponente, y ajusta su dirección (aum.x y aum.y) en consecuencia.

#Interacción entre Elementos

1-Movimiento de la pelota:

1.1- La pelota se mueve automáticamente tras presionar E.

1.2- Si la pelota choca con las barras, su dirección en el eje x se invierte (aum.x).

1.3- Si choca con los bordes superior o inferior del campo, su dirección en el eje y se invierte (aum.y).

2- Colisiones:

2.1- La función choque detecta si la pelota toca las barras del jugador u oponente y ajusta su trayectoria.

2.2- Si la pelota cruza los bordes izquierdo o derecho, se actualiza el marcador y se reinicia su posición.

3- Inteligencia Artificial del oponente:

3.1- La posición vertical del oponente sigue la posición de la pelota, asegurándose de que intente bloquearla.

#Características del Campo de Juego

Límites: Dibujados con caracteres ═ y ║. Las funciones limites() y red() crean el campo.

Zona central: Una línea vertical divide el campo en dos mitades (red()).

Bordes: Si la pelota toca un borde (pel.y < 1 o pel.y > ALTO - 1), su dirección se invierte.

#Funciones Principales

#gotoxy(int x, int y):

Permite posicionar el cursor en una coordenada específica en la consola.

#main():

Coordina todas las funciones y controla el bucle principal del juego.

#update():

Verifica si se deben iniciar o reiniciar las posiciones del juego.
Detecta si la pelota ha cruzado un límite y actualiza el marcador.

y eso seria toda la informacion acerca de el juego, cualquier mejora es bien recibida, gracias.
J.P.P.H
