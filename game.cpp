  #include "TXLib.h"
#include "Monstr.cpp"

struct Pulya
{
    int x;
    int y;
    bool letit;
    bool letit_vlevo;
};

int ubitRobot(int x_monstr, int y_monstr, int x, int y, int hp, bool viden);

bool click(int x, int y)
{
    if (txMouseButtons() == 1 && // ���� ������ ����� ������ ����
            txMouseX() >= x && // � ���� ��������� �� ������...
            txMouseX() <= x + 60 &&
            txMouseY() >= y &&
            txMouseY() <= y + 60)
    {

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    txCreateWindow(800, 700);

    int x = 100;
    int y = 100;
    int speed = 6;
    int hp = 100;
    HDC robot = txLoadImage("Pics\\Robot.bmp");


	HDC fon = txLoadImage("Pics\\qwerty.bmp");
	bool gameOver = false;

    int KOLICH_KARTINOK_VRAGOV = 8;
    HDC vragiPic[KOLICH_KARTINOK_VRAGOV];
    int nomer_vraga = 0;
    vragiPic[0] = txLoadImage("Pics\\���� 1.bmp");
    vragiPic[1] = txLoadImage("Pics\\���� 2.bmp");
    vragiPic[2] = txLoadImage("Pics\\���� 3.bmp");
    vragiPic[3] = txLoadImage("Pics\\���� 4.bmp");
    vragiPic[4] = txLoadImage("Pics\\Robot.bmp");
    vragiPic[5] = txLoadImage("Pics\\�.�.�.�.�.bmp");
    vragiPic[6] = txLoadImage("Pics\\����.bmp");
    vragiPic[7] = txLoadImage("Pics\\����1.bmp");

    HDC pers1Pic = txLoadImage("Pics\\����_1.bmp");
    HDC pers2Pic = txLoadImage("Pics\\����_2.bmp");
    HDC pers3Pic = txLoadImage("Pics\\����_3.bmp");
    HDC pers4Pic = txLoadImage("Pics\\����_4.bmp");
    HDC pers5Pic = txLoadImage("Pics\\Robot.bmp");

    int ubito_vragov = 0;
    int nomer_urovnya = 1;


    int kolich_vragov = 300;
    Monstr vrag1[kolich_vragov];
    for (int nomery = 0; nomery < 20 ; nomery++)
    {
        for (int nomer = 0; nomer < 15; nomer++)
        {
            vrag1[15*nomery + nomer]  = {350 + 50 * nomer,100 + 50 * nomery, 10, true,vragiPic[0]};
        };
    }




    bool pers_vybran = false;
    bool vrag_vybran = false;

    Pulya puli = {100, 100, false, false};



    txPlaySound ("������ ��� ����.wav");

    //����
    txBitBlt(txDC(), 0, 0, 800, 700, fon, 0, 0);
    txSelectFont("Times New Roman", 30);
    txDrawText(0,0,txGetExtentX(), 200,"�������� �����");
    while (!vrag_vybran)
    {
        RECT vrag1Rect = {80, 210, 130, 263};

        txTransparentBlt(txDC(), vrag1Rect.left, vrag1Rect.top, vrag1Rect.right - vrag1Rect.left, vrag1Rect.bottom - vrag1Rect.top, vragiPic[0], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag1Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 0;
        }


        RECT vrag2Rect = {280, 210, 330, 263};
        txTransparentBlt(txDC(), vrag2Rect.left, vrag2Rect.top, vrag2Rect.right - vrag2Rect.left, vrag2Rect.bottom - vrag2Rect.top, vragiPic[1], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag2Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 1;
        }


        RECT vrag3Rect = {480, 210, 530, 263};
        txTransparentBlt(txDC(), vrag3Rect.left, vrag3Rect.top, vrag3Rect.right - vrag3Rect.left, vrag3Rect.bottom - vrag3Rect.top, vragiPic[2], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag3Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 2;
        }


        RECT vrag4Rect = {680, 210, 730, 263};
        txTransparentBlt(txDC(), vrag4Rect.left, vrag4Rect.top, vrag4Rect.right - vrag4Rect.left, vrag4Rect.bottom - vrag4Rect.top, vragiPic[3], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag4Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 3;
        }

        RECT vrag5Rect = {680, 350, 730, 403};
        txTransparentBlt(txDC(), vrag5Rect.left, vrag5Rect.top, vrag5Rect.right - vrag5Rect.left, vrag5Rect.bottom - vrag5Rect.top, vragiPic[4], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag5Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 4;
        }

        RECT vrag6Rect = {480, 350, 530, 403};
        txTransparentBlt(txDC(), vrag6Rect.left, vrag6Rect.top, vrag6Rect.right - vrag6Rect.left, vrag6Rect.bottom - vrag6Rect.top, vragiPic[5], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag6Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 5;
        }

        RECT vrag7Rect = {280, 350, 330, 403};
        txTransparentBlt(txDC(), vrag7Rect.left, vrag7Rect.top, vrag7Rect.right - vrag7Rect.left, vrag7Rect.bottom - vrag7Rect.top, vragiPic[6], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag7Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 6;
        }


        RECT vrag8Rect = {80, 350, 130, 403};
        txTransparentBlt(txDC(), vrag8Rect.left, vrag8Rect.top, vrag8Rect.right - vrag8Rect.left, vrag8Rect.bottom - vrag8Rect.top, vragiPic[7], 0, 0, TX_WHITE);
        if (txMouseButtons() == 1 && In(txMousePos(), vrag8Rect))
        {
            vrag_vybran = true;
            nomer_vraga = 7;
        }


        txSleep(10);
    }


    for (int nomer = 0; nomer < kolich_vragov; nomer = nomer  +1)
    {
        vrag1[nomer].pic = vragiPic[nomer_vraga];
    }



    txSleep(2000);




    txBitBlt(txDC(), 0, 0, 800, 700, fon, 0, 0);
    txSelectFont("Times New Roman", 30);
    txDrawText(0,0,txGetExtentX(), 200,"�������� �����");
    while (!pers_vybran)
    {
        txTransparentBlt(txDC(), 0, 10, 60, 56, pers1Pic, 0, 0, TX_WHITE);
        if (click(0, 60))
        {
            pers_vybran = true;
            robot = pers1Pic;
        }

        txTransparentBlt(txDC(), 200, 10, 60, 56, pers2Pic, 0, 0, TX_WHITE);
        if (click(200, 60))
        {
            pers_vybran = true;
            robot = pers2Pic;
        }

        txTransparentBlt(txDC(), 400, 10, 60, 56, pers3Pic, 0, 0, TX_WHITE);
        if (click(400, 60))
        {
            pers_vybran = true;
            robot = pers3Pic;
        }

        txTransparentBlt(txDC(), 600, 10, 60, 56, pers4Pic, 0, 0, TX_WHITE);
        if (click(600, 60))
        {
            pers_vybran = true;
            robot = pers4Pic;
        }

        txTransparentBlt(txDC(), 400, 210, 60, 56, pers5Pic, 0, 0, TX_WHITE);
        if (click(400, 200))
        {
            pers_vybran = true;
            robot = robot;
        }

        txSleep(10);
    }


    txTextOut(500,600,"���������� ���������. �������� ��������");
    txSleep(5000);

    //����

    txSelectFont("Times New Roman", 16);
    while(!GetAsyncKeyState(VK_ESCAPE) and gameOver == false)
    {
        //������ �
        if (GetAsyncKeyState('P'))
        {
            //������ �
            while (GetAsyncKeyState('P'))
            {
                txSleep(10);
            }

            //����� ������ �
            while (!GetAsyncKeyState('P'))
            {
                 txDrawText(0,0,txGetExtentX(), 200,"�����");
                txSleep(10);
            }
            txSleep(1000);
        }

        //���
        txBegin();
        txBitBlt(txDC(), 0, 0, 800, 700, fon, 0, 0);

        //��������
        txSetFillColor(TX_WHITE);
        txRectangle(0, 0, 0 + 3 * 100, 10);
        txSetFillColor(TX_RED);
        txRectangle(0, 0, 0 + 3 * hp, 10);

        char ubito_vragov_str[100];
        sprintf(ubito_vragov_str, "����� ������: %d", ubito_vragov);
        txTextOut(600, 25, ubito_vragov_str);

        char nomer_urovnya_str[100];
        sprintf(nomer_urovnya_str, "����� ������: %d", nomer_urovnya);
        txTextOut(600, 10, nomer_urovnya_str);

        //���������
        txSetFillColor (TX_RED);
        for (int pulya_x = x + 30; pulya_x < puli.x; pulya_x += 5)
        {
            txCircle (pulya_x, puli.y, 3);
        }
        for (int pulya_x = x + 30; pulya_x > puli.x; pulya_x -= 5)
        {
            txCircle (pulya_x, puli.y, 3);
        }

        txTransparentBlt(txDC(), x, y, 60, 56, robot, 0, 0, TX_WHITE);
        bool hot_odin_zhiv = false;
        for (int nomer = 0; nomer < kolich_vragov; nomer = nomer  +1)
        {
            if (vrag1[nomer].zhiv)
            {
                hot_odin_zhiv = true;
                txTransparentBlt(txDC(), vrag1[nomer].x, vrag1[nomer].y, 50, 53, vrag1[nomer].pic, 0, 0, TX_WHITE);
            }
        }

        //����� �����
        if (hot_odin_zhiv == false)
        {
            nomer_vraga = nomer_vraga + 1;

            for (int nomer = 0; nomer < kolich_vragov; nomer = nomer  +1)
            {
                vrag1[nomer].pic = vragiPic[nomer_vraga % KOLICH_KARTINOK_VRAGOV];
                vrag1[nomer].zhiv = true;
                vrag1[nomer].ostalos_zhit = 1000;
            }

            nomer_urovnya = nomer_urovnya + 1;
        }

        ubito_vragov = kolich_vragov * (nomer_urovnya - 1);
        for (int nomer = 0; nomer < kolich_vragov; nomer = nomer  + 1)
        {
            if (vrag1[nomer].zhiv)
            {
                hot_odin_zhiv = true;
                txTransparentBlt(txDC(), vrag1[nomer].x, vrag1[nomer].y, 50, 53, vrag1[nomer].pic, 0, 0, TX_WHITE);
            }
            else
            {
                ubito_vragov = ubito_vragov + 1;
            }
        }


        //������ ���������� �������� �����
        for (int nomer = 0; nomer < kolich_vragov; nomer = nomer  +1)
        {
            vrag1[nomer].x = vrag1[nomer].x + random (-5, 6);
            vrag1[nomer].y = vrag1[nomer].y + random (-5, 6);
            vrag1[nomer].x = moveMonstrX(vrag1[nomer].x, x);
            vrag1[nomer].y = moveMonstrY(vrag1[nomer].y, y);
            //��������, ��� �� ������� �����
            vrag1[nomer].x = checkMonstrX(vrag1[nomer].x);
            vrag1[nomer].y = checkMonstrY(vrag1[nomer].y);


            //������ ����
            vrag1[nomer].ostalos_zhit = getOstalosZhitMonstr(vrag1[nomer].x, vrag1[nomer].y, puli.x, puli.y, vrag1[nomer].ostalos_zhit);

            if (vrag1[nomer].ostalos_zhit <= 0)
            {
                vrag1[nomer].zhiv = false;
            }
        }



        txSetColor(TX_BLACK);
        //risovatRobot(200, y);

        //�������� �������� �����
        if (hp > 0)
        {
            if (GetAsyncKeyState(VK_LEFT)&& x > 0 + 40)
            {
                x = x - speed;
            }
            else if (GetAsyncKeyState(VK_RIGHT)&& x < txGetExtentX()  - 100)
            {
                x = x + speed;
            }
        }

        //�������� �������� �����
        if (hp > 0)
        {
            if (GetAsyncKeyState(VK_UP) && y > 0 + 40)
            {
                y = y- speed;
            }
            else if (GetAsyncKeyState(VK_DOWN) && y < txGetExtentY() * 80 / 100 - 100)
            {
                y = y+ speed;
            }
        }


        if (hp <= 0)
        {
            gameOver = true;
        }

        //�������� hp ����� ������ ���������� � �������
        for (int nomer = 0; nomer < kolich_vragov; nomer = nomer + 1)
        {
            hp = ubitRobot(vrag1[nomer].x, vrag1[nomer].y, x, y, hp, vrag1[nomer].zhiv);
        }


//�������
        if (GetAsyncKeyState(VK_SPACE))
        {
            if (puli.x < vrag1[0].x)
            {
                puli.letit_vlevo = false;
            }
            else
            {
                puli.letit_vlevo = true;
            }
            puli.letit = true;
        }

        if (puli.letit and puli.letit_vlevo)
        {
            puli.x = puli.x - 40;
        }
        else if (puli.letit and !puli.letit_vlevo)
        {
            puli.x = puli.x + 40;
        }
        else
        {
            puli.x = x + 40;
            puli.y = y + 15;
        }

        if (puli.x > txGetExtentX() or puli.x < 0)
        {
            puli.letit = false;
        }


        txEnd();
        txSleep(10);
    }



    //���� ���������
	txDeleteDC(robot);
	txDeleteDC(fon);
	for (int i = 0; i < 4; i = i + 1)
	{
        txDeleteDC(vragiPic[i]);
	}


	txDeleteDC(pers1Pic);
	txDeleteDC(pers2Pic);
	txDeleteDC(pers3Pic);
	txDeleteDC(pers4Pic);

	return 0;
 }

int ubitRobot(int x_monstr, int y_monstr, int x, int y, int hp, bool viden)
{
        if (x_monstr      < x + 10 and
            x_monstr + 5 > x and
            y_monstr      < y + 10 and
            y_monstr + 5 > y and
            //� ������ ������� == ���
            viden == true)

        {
            hp = hp - 1;
        }

        return hp;

}
