# Juego de Nave: Enemigos y Potenciadores

Este es un juego simple basado en consola donde controlas una nave que debe esquivar enemigos y recoger potenciadores mientras dispara para eliminar amenazas. El juego está implementado en C++.

## Características del Juego

- **Movimiento de la Nave**: La nave puede moverse hacia la izquierda y derecha.
- **Enemigos**: Los enemigos aparecen periódicamente en posiciones aleatorias y descienden línea por línea. La nave debe esquivarlos o dispararles para eliminarlos.
- **Potenciadores**: Recolectar potenciadores incrementa la velocidad de la nave.
- **Disparos**: La nave puede disparar hacia arriba para destruir enemigos.
- **Mapa**: Se utiliza una cuadrícula con bordes visibles para representar el área de juego.

## Controles del Juego

- `a`: Mover la nave hacia la izquierda.
- `d`: Mover la nave hacia la derecha.
- `Espacio`: Disparar.
- `x`: Salir del juego.

## Requisitos

- Compilador de C++ compatible (como GCC o MSVC).
- Sistema operativo Windows (se utiliza la librería `windows.h`).

## Instalación y Ejecución

1. **Clonar el repositorio** o copiar el código fuente en un archivo con extensión `.cpp`.
2. Abrir una terminal o un IDE de C++.
3. Compilar el archivo con un comando como:
   ```bash
   g++ funcionalidad7_potenciadores_velocidad.cpp -o funcionalidad7_potenciadores_velocidad
   ```
4. Ejecutar el programa:
   ```bash
   ./juego_nave
   ```

## Estructura del Código

### Variables Principales

- **Mapa**:
  - Representado por una matriz 2D (`mapa`) que contiene bordes, enemigos, potenciadores y la nave.
- **Nave**:
  - Su posición está definida por `posX` (columna) y `posY` (fila).
- **Enemigos**:
  - Almacenados como coordenadas en un vector de pares (`vector<pair<int, int>> enemigos`).
- **Potenciadores**:
  - Sus posiciones se almacenan en vectores (`potenciadoresX`, `potenciadoresY`).

### Funciones Clave

1. **inicializarMapa**:
   Configura el mapa inicial con bordes y espacios vacíos.

2. **dibujarMapa**:
   Actualiza y muestra en pantalla la posición de la nave, enemigos y potenciadores.

3. **moverNave**:
   Cambia la posición de la nave según la entrada del jugador.

4. **moverEnemigos**:
   Desplaza a los enemigos hacia abajo. Elimina los que llegan al borde inferior.

5. **generarEnemigo**:
   Agrega un enemigo en una posición aleatoria de la parte superior del mapa.

6. **generarPotenciador**:
   Crea un potenciador en una posición aleatoria en la mitad superior del mapa.

7. **verificarPotenciadores**:
   Detecta si la nave recoge un potenciador y aumenta la velocidad.

8. **disparar**:
   Simula un disparo hacia arriba para destruir enemigos en su trayectoria.

9. **main**:
   Contiene el bucle principal que actualiza el estado del juego y maneja las entradas del jugador.

## Mejoras Futuras

- Implementar niveles con mayor dificultad.
- Añadir más tipos de potenciadores con efectos distintos.
- Incorporar enemigos con comportamientos variables.
- Agregar una interfaz para mostrar puntajes o vidas restantes.

## Autor
Este juego fue desarrollado como un proyecto de práctica en C++ para aprender programación básica de juegos.

---

¡Disfruta jugando y aprendiendo con este proyecto! 🚀
