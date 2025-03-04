# PathFinder-Labyrinth
## Descripción
Este proyecto consiste en la resolución de un laberinto definido por caracteres. El objetivo es determinar si un agente, partiendo desde una posición inicial (x, y), puede llegar a una recompensa ('t') dentro del laberinto. Adicionalmente, el sistema permite generar laberintos de manera aleatoria y almacenar en un archivo los intentos exitosos y fallidos del agente.

## Características
- Entrada manual de laberintos mediante caracteres.
- Generación automática de laberintos con caracteres aleatorios.
- Movimientos permitidos: arriba, abajo, izquierda y derecha.
- Almacenamiento en archivo de las posiciones que llegan o no al tesoro.
- Representación del laberinto con los siguientes caracteres:
  - `.` : Camino transitable.
  - `X` : Obstáculo, no se puede cruzar.
  - `t` : Tesoro, el destino deseado.
  - `a, e, i, o, u` : Otros elementos dentro del laberinto.

## Instalación
1. Clona este repositorio:
   ```bash
   git clone https://github.com/tu-usuario/tu-repositorio.git
   ```
2. Accede al directorio del proyecto:
   ```bash
   cd tu-repositorio
   ```
   
## Uso
### Modo Manual
1. Ejecuta el programa.
2. Introduce el tamaño de el laberinto.
3. Introduce el laberinto según el formato descrito.
4. Indica la posición inicial del agente.
5. El sistema determinará si es posible llegar al tesoro.
6. Se guardará el resultado en un archivo `.txt` o `.dat`.

### Modo Automático
1. Selecciona la opción de generación automática.
2. El sistema creará un laberinto aleatorio.
3. Se realizará la búsqueda del tesoro y se registrará el resultado.

## Archivo de Salida
El programa genera un archivo de texto con las posiciones exploradas y sus resultados:
```
# Formato del archivo
Llega al tesoro: (x1, y1), (x2, y2), ...
No llega al tesoro: (x3, y3), (x4, y4), ...
```

## Tecnologías Utilizadas
- Lenguaje de programación: C++.
- Archivos de texto para almacenamiento de resultados.

## Autor
Desarrollado por [Jeffry Valverde, Javier Gonzales y Rodrigo Retana].
