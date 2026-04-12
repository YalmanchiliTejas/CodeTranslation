#include <cstdio>
#include<iostream>
char s[100][100];
int c[100][100],a,b,ans,cnt;
int d[2][2]={1,0,0,1};
void bfs(int x,int y)
{
   if((x==a-1)&&(y==b-1)) {ans=1;return ;}
   for(int i=0;i<2;i++)
    {
        int dx=x+d[i][0];
        int dy=y+d[i][1];
        if(s[dx][dy]=='#'&&dx>=0&&dx<a&&dy>=0&&dy<=b)
        bfs(dx,dy);
    }
}
int main()
{
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        for(int i=0;i<a;i++)
         {
             scanf("%s",s[i]);
             for(int j=0;j<b;j++)
                if(s[i][j]=='#') cnt++;
         }
         ans=0;
         bfs(0,0);
         if(ans==1 && cnt==a+b-1) printf("Possible\n");
         else printf("Impossible\n");

    }
    return 0;
}
