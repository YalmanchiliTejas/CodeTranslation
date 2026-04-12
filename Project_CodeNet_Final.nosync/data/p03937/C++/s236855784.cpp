#include<cstdio>
#include<cstring>
int s[2][2]={0,1,1,0},m,n,bbb,sum,maxx;
char a[10000][10000];
void dfs(int x,int y)
{
    int xx,yy;
    if(x==m-1&&y==n-1){bbb=1;return;}
    for(int i=0;i<2;i++)
    {if(x==m-1&&y==n-1){bbb=1;return;}
         xx=x+s[i][0];
         yy=y+s[i][1];
         if(a[xx][yy]=='#'&&xx>=0&&xx<m&&yy>=0&&yy<n)
          {
               a[xx][yy]='*';sum=sum+1;//printf("%d %d\n",xx,yy);
               dfs(xx,yy);
          }
    }
}
int main()
{
     while(scanf("%d%d",&m,&n)==2)
     {
          sum=1;bbb=0;maxx=0;
          for(int i=0;i<m;i++)
               scanf("%s",a[i]);
          for(int i=0;i<m;i++)
               for(int j=0;j<n;j++)
               if(a[i][j]=='#')
               maxx=maxx+1;
          dfs(0,0);
          a[0][0]='*';
          //printf("%d %d",maxx,sum);
          if(bbb==1&&maxx==m+n-1)
          printf("Possible\n");
          else printf("Impossible\n");
     }
     return 0;
}
