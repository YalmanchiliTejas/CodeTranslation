#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int d[15][15];
int weight[15][105];
int xy[105][105];
void wa()
{
    puts("Impossible");
}
int check_ans[15];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a,b;
    scanf("%d%d",&a,&b);
    int i,j;
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=b;j++)
        {
            scanf("%d",&d[i][j]);
        }
    }
    int x,y;
    int sum=10401;
    for (x=0;x<=100;x++)
    {
        for (y=0;y<=100;y++)
        {
            xy[x][y]=-1;
            for (i=1;i<=a;i++)
            {
                for (j=1;j<=b;j++)
                {
                    xy[x][y]=max(xy[x][y],d[i][j]-i*x-j*y);
                }
            }
            if (xy[x][y]<0) sum--;
        }
    }
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=b;j++)
        {
            int ans=105;
            for (x=0;x<=100;x++)
            {
                for (y=0;y<=100;y++)
                {
                    if (xy[x][y]<0) continue;
                    ans=min(ans,xy[x][y]+i*x+j*y);
                }
            }
            if (ans!=d[i][j])
            {
                wa();
                return 0;
            }
        }
    }
    puts("Possible");
    printf("202 %d\n",sum);
    for (i=1;i<=100;i++)
    {
        printf("%d %d X\n",i,i+1);
    }
    for (i=102;i<=201;i++)
    {
        printf("%d %d Y\n",i,i+1);
    }
    for (i=0;i<=100;i++)
    {
        for (j=0;j<=100;j++)
        {
            if (xy[i][j]<0) continue;
            printf("%d %d %d\n",i+1,202-j,xy[i][j]);
        }
    }
    printf("1 202\n");
    return 0;
} 
