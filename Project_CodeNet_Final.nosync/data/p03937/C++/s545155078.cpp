#include <stdio.h>
#include <string.h>

char map_[10][10];
int temp,one,dian,ok;
int h,w;
void dfs(int x,int y,int s)
{
    if (x==h&&y==w)
    {
        if (temp==1&&s==one)
            ok=1;
        if (temp==2&&s==dian)
            ok=1;
        return;
    }
    if (y+1<=w&&map_[1][1]==map_[x][y+1])
        dfs(x,y+1,s+1);
    if (x+1<=h&&map_[1][1]==map_[x+1][y])
        dfs(x+1,y,s+1);
}

int main()
{
    while (scanf("%d%d",&h,&w)!=EOF)
    {
        getchar();
        one=dian=0;
        for (int i=1;i<=h;i++)
        {
            for (int j=1;j<=w;j++)
            {
                scanf("%c",&map_[i][j]);
                if (map_[i][j]=='#')
                    one++;
                else
                    dian++;
            }
            getchar();
        }
        ok=0;
        if (map_[1][1]=='#')
            temp=1;
        else
            temp=2;
        dfs(1,1,1);
        if (ok)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}