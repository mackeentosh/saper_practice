#include "painter.hpp"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void Painter::drawClosedField(int x, int y)
{
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width, (y + 1) * cell_height);
    glVertex2f(x * cell_width, (y + 1) * cell_height);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(x * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width - 1, y * cell_height);
    glVertex2f(x * cell_width, y * cell_height);
    glVertex2f(x * cell_width, (y + 1) * cell_height - 1);
    glEnd();
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f((x + 1) * cell_width - 1, y * cell_height);
    glVertex2f((x + 1) * cell_width - 1, (y + 1) * cell_height - 1);
    glVertex2f(x * cell_width, (y + 1) * cell_height - 1);
    glVertex2f((x + 1) * cell_width - 1, (y + 1) * cell_height - 1);
    glEnd();
}

void Painter::drawOpenedField(int x, int y, int minesAround)
{
    drawOpenedField(x, y);
    if (minesAround > 0)
    {
        switch (minesAround)
        {
        case 1:
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        case 2:
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
        case 3:
            glColor3f(1.0f, 0.0f, 0.0f);
            break;
        case 4:
            glColor3f(0.0f, 0.7f, 0.0f);
            break;
        case 5:
            glColor3f(0.5f, 0.4f, 0.0f);
            break;
        case 6:
            glColor3f(0.0f, 0.8f, 0.5f);
            break;
        case 7:
            glColor3f(0.1f, 0.1f, 0.1f);
            break;
        case 8:
            glColor3f(0.3f, 0.3f, 0.3f);
            break;
        }
        glRasterPos2f(x * cell_width + (15 - 9) / 2 + 1, (y + 1) * cell_height - 1);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + minesAround);
    }
}

void Painter::drawFlag(int x, int y)
{
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width, (y + 1) * cell_height);
    glVertex2f(x * cell_width, (y + 1) * cell_height);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x * cell_width + cell_width / 2, y * cell_height + 3);
    glVertex2f(x * cell_width + cell_width / 2, (y + 1) * cell_height - 3);
    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x * cell_width + cell_width / 2, y * cell_height + 3);
    glVertex2f(x * cell_width + cell_width / 2 - 3, y * cell_height + 3 + 3);
    glVertex2f(x * cell_width + cell_width / 2, y * cell_height + 3 + 3 + 3);
    glEnd();
}

void Painter::drawMine(int x, int y)
{
    drawOpenedField(x, y);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i)
        glVertex2f(x * cell_width + cell_width / 2 + 5.0f * cos(2 * 3.1415926 * i / 5),
                   y * cell_height + cell_height / 2 + 5.0f * sin(2 * 3.1415926 * i / 5));
    glEnd();
}

void Painter::drawOpenedField(int x, int y)
{
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(x * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width, y * cell_height);
    glVertex2f((x + 1) * cell_width, (y + 1) * cell_height);
    glVertex2f(x * cell_width, (y + 1) * cell_height);
    glEnd();
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f((x + 1) * cell_width - 1, y * cell_height);
    glVertex2f((x + 1) * cell_width - 1, (y + 1) * cell_height - 1);
    glVertex2f(x * cell_width, (y + 1) * cell_height - 1);
    glVertex2f((x + 1) * cell_width - 1, (y + 1) * cell_height - 1);
    glEnd();
}
