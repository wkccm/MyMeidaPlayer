﻿#include "hvideownd.h"
#include "confile.h"
#include "htime.h"

HVideoWnd::HVideoWnd(QWidget *parent)
{
    fps = 0;
    framecnt = 0;
    tick = 0;
    draw_time = g_confile->Get<bool>("draw_time", "ui", false);
    draw_fps = g_confile->Get<bool>("draw_fps", "ui", false);
    draw_resolution = g_confile->Get<bool>("draw_resolution", "ui", false);
}

void HVideoWnd::calcFPS()
{
    if(gettick_ms() - tick > 1000)
    {
        fps = framecnt;
        framecnt = 0;
        tick = gettick_ms();
    }
    else
    {
        ++framecnt;
    }
}
