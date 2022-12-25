#include "game.hpp"
#include "painter.hpp"
#include <GL/glut.h>

Game game;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    game.draw();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_UP)
    {
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            game.open(x / Painter::cell_width, y / Painter::cell_height);
            break;
        case GLUT_RIGHT_BUTTON:
            game.mark(x / Painter::cell_width, y / Painter::cell_height);
            break;
        }
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Game::window_width * Painter::cell_width, Game::window_height * Painter::cell_height);
    glutInitWindowPosition(100, 120);
    glutCreateWindow("MineSweeper");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Game::window_height * Painter::cell_height, Game::window_width * Painter::cell_width, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
