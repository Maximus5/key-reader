// sudo apt-get install g++ libncurses-dev
// g++ key-curses.cpp -lncurses -o kc

/*
Copyright (c) 2016-2017 Maximus5
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <curses.h>

int main()
{
    int ch, esc = 0;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    //mouseinterval(0);
    noecho();
    printf("Press <Esc> twice to exit\r\n");
    refresh();
    while (esc <= 1)
    {
        ch = getch();
        if (ch == ERR)
        {
            printf("  getch fails, code=%i\r\n", (int)ch);
            break;
        }
        printf("<x%02x:%c> %s\r\n",
            ch, (ch>32 && ch<=127 && ch!=10 && ch!=13)?ch:' ',
            keyname(ch));
        if (ch == KEY_MOUSE)
        {
            MEVENT event;
            int mrc = getmouse(&event);
            if (mrc == OK)
                printf("  bstate=x%02X x=%i y=%i\r\n", (unsigned)event.bstate, event.x, event.y);
            else
                printf("  getmouse fails, code=%i\r\n", mrc);
        }
        if (ch == 0x1B) esc++; else esc = 0;
        refresh();
    }
    endwin(); 
    return 0;
}

