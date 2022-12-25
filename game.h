#pragma once

class Painter
{
public:
    enum { cell_width = 16, cell_height = 16 };
    void drawClosedField(int x, int y);
    void drawOpenedField(int x, int y, int minesAround);
    void drawFlag(int x, int y);
    void drawMine(int x, int y);
private:
    void drawOpenedField(int x, int y);
};
