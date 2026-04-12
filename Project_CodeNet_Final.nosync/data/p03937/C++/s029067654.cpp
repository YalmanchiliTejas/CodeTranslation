#include "stdio.h"
char map[12][12];
int n,h,w;
void begin()
{
    int i,j;
    char c;
    n=0;
    for (i=0;i<=h+1;i++)
    {
        for (j=0;j<=w+1;j++)
        {
            if (i*j == 0 || i==h+1 || j==w+1)
            {
                map[i][j] == '.';
            }
            else
            {
               while (c = getchar())
               {
                  if (c == '\n')
                  {
                    continue;
                  }
                  map[i][j] = c;
                  break;
               }
            }
            if (map[i][j] == '#')
            {
                n++;
            }
        }
    }
}
int main()
{
    int x,y,i,u;
    while (scanf ("%d%d",&h,&w) != EOF)
    {
         begin();
         x = y = i = 1;
         u = n;
         while (u--)
         {
             if (map[x][y+1] == '#')
             {
                 y++;
                 i++;
             }
             else if (map[x+1][y] == '#')
             {
                 x++;
                 i++;
             }
         }
         printf ("%s\n",i==n?"Possible":"Impossible");
    }
    return 0;
}
