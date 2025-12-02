#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int ac, char **av)
{

    if (ac != 4)
        return 1;
    
    int w = atoi(av[1]), h = atoi(av[2]), it = atoi(av[3]);
    if (w <= 0 || h <= 0 || it < 0)
        return 1;

    int *b = calloc((size_t)w*h, sizeof(int));
    int *n = calloc((size_t)w*h, sizeof(int));

    if (!b || !n)
        return 1;
    
    char c;
    int x=0, y=0, p=0;
    while(read(0, &c, 1) > 0)
    {
        if (c == 'w' && y > 0) y--; 
        else if (c == 's' && y < h-1) y++;
        else if (c == 'a' && x > 0) x--; 
        else if (c == 'd' && x < w-1) x++;
        else if (c == 'x') {p = !p; }
        if (p) b[y*w + x] = 1;
    }

    for (int i = 0; i < it; ++i)
    {
        for (int nh = 0; nh < h; ++nh)
        {
            for (int nw = 0; nw < w; ++nw)
            {
                int nb = 0; 
                for (int ny = -1; ny <= 1; ny++)
                {
                    for (int nx = -1; nx <= 1; nx++)
                    {
                        int tmpY = nh + ny, tmpX = nw + nx;
                        if (nx || ny)
                        {
                            if (( tmpY >= 0 && tmpY < h) && (tmpX >= 0 && tmpX < w))
                                nb += b[tmpY*w + tmpX];
                        }
                    }
                }
                n[nh * w + nw] = (b[nh * w + nw] ? (nb == 2 || nb == 3) : (nb == 3));
            }
        }

        int *tmp = b; b = n; n = tmp;
    }
    
    for (int py = 0; py < h; py++)
    {
        for(int px = 0; px < w; px++)
            putchar((b[py*w + px] ? '0' : ' '));
        putchar('\n');
    }

    free(b), free(n);
    return 0;
}

