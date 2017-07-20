#include <curses.h>

int main()
{
    int ch, esc = 0;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    printf("Press <Esc> twice to exit\r\n");
    refresh();
    while (esc <= 1)
    {
        ch = getch();
        if (ch == ERR) break;
        printf("<x%02x:%c> %s\r\n",
            ch, (ch>0 && ch<=127 && ch!=10 && ch!=13)?ch:' ',
            keyname(ch));
        if (ch == 0x1B) esc++; else esc = 0;
        refresh();
    }
    endwin(); 
    return 0;
}

