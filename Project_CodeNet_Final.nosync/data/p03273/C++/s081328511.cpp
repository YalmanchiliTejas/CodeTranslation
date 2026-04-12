#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 105;
int flag[maxn][maxn];
char maze[maxn][maxn];
int row[maxn],colum[maxn];

int main()
{
    int h,w;
    int i,j;

    scanf("%d%d",&h,&w);
    for(i = 0;i < h;i++)
    {
        getchar();
        for(j = 0;j < w;j++)
        {
            scanf("%c",&maze[i][j]);
        }
    }
    for(i = 0;i < h;i++)
    {
        int f1 = 0;
        for(j = 0;j < w;j++)
        {
            if(maze[i][j] == '#')
            {
                f1 = 1;
                break;
            }
        }
        if(f1 == 0)
        {
            row[i] = 1;
            for(j = 0;j < w;j++)
                flag[i][j] = 1;//not print
        }
    }
    for(j = 0;j < w;j++)
    {
        int f2 = 0;
        for(i = 0;i < h;i++)
        {
            if(maze[i][j] == '#')
            {
                f2 = 1;
                break;
            }
        }
        if(!f2)
        {
            colum[j] = 1;
            for(i = 0;i < h;i++)
                flag[i][j] = 1;
        }
    }
    for(i = 0;i < h;i++)
    {
        for(j = 0;j < w;j++)
        {
            if(!flag[i][j]) printf("%c",maze[i][j]);
        }
        if(!row[i]) printf("\n");
    }

    return 0;
}
