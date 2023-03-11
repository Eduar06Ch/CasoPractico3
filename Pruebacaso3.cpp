#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// Función para trazar un círculo utilizando el algoritmo 
void drawCircle(int radius, int xc, int yc) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    glColor3f(1.0, 1.0, 1.0); // Establecemos el color a blanco
    glBegin(GL_POINTS); // Iniciamos la definición de puntos
    while (x <= y) { // Mientras no se hayan trazado todos los octantes del círculo
        // Trazamos los puntos correspondientes a cada octante del círculo utilizando las fórmulas simétricas
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc + x, yc - y);
        // Actualizamos las coordenadas y la variable de decisión para el siguiente punto
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd(); // Finalizamos la definición de puntos
}

// Función para dibujar la línea diagonal
void drawLine(int length) {
    glColor3f(1.0, 1.0, 1.0); // Establecemos el color a blanco
    glBegin(GL_LINES); // Iniciamos la definición de una línea
    glVertex2i(0, 0); // Definimos el primer punto en (0, 0)
    glVertex2i(length, length); // Definimos el segundo punto en (length, length)
    glEnd(); // Finalizamos la definición de la línea
}

// Función para dibujar la escena
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Borramos el buffer de color
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-50.0, -50.0, 0.0); // Desplazamos el origen a (-50, -50) para centrar el círculo y la línea
    drawCircle(25, 50, 50); // Dibujamos el círculo con radio 25 y centro en (50, 50)
    drawLine(50); // Dibujamos la línea diagonal con longitud 50
    glFlush();
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Círculo con línea diagonal");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

