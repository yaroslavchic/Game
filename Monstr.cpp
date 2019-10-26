#include "TXLib.h"

struct Monstr
{
    int x;
    int y;
    double ostalos_zhit;
    bool zhiv;
    bool zhiv2;
    HDC pic;


};

int checkMonstrX(int x_monstr)
{
    if (x_monstr < 0)
    {
        x_monstr = 0;
    }
    else if (x_monstr > txGetExtentX() - 50)
    {
        x_monstr = txGetExtentX() - 50;
    }

    return x_monstr;
}


int checkMonstrY(int y_monstr)
{
    if (y_monstr < 0)
    {
        y_monstr = 0;
    }
    else if (y_monstr > txGetExtentX() - 50)
    {
        y_monstr = txGetExtentX() - 50;
    }

    return y_monstr;
}

double getOstalosZhitMonstr(int x_monstr, int y_monstr, int x_puli, int y_puli, double zhiv)
{
    if (x_monstr      < x_puli and
        x_monstr + 50 > x_puli and
        y_monstr      < y_puli and
        y_monstr + 50 > y_puli and
        zhiv > 5)
    {
       zhiv = 5;
    }

    if (zhiv <= 5)
    {
        zhiv = zhiv - 0.1;
    }

    return zhiv;
 }


int moveMonstrX(int x_monstr, int x)
{
    if (x_monstr < x)
    {
        x_monstr = x_monstr + 1;
    }
    else if (x_monstr > x)
    {
        x_monstr = x_monstr - 1;
    }

    return x_monstr;
}


int moveMonstrY(int y_monstr, int y)
{
    if (y_monstr < y)
    {
        y_monstr = y_monstr + 1;
    }
    else if (y_monstr > y)
    {
        y_monstr = y_monstr - 1;
    }

    return y_monstr;
}


