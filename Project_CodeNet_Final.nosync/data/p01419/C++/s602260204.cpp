#include <iostream>
#include <cstdio>
#include <cstring>
#define N 55
using namespace std;
int n,m,k;
char g[N][N];
int p[N][N];
int on[N][N];
int off[N][N];
int sb[N][N];
bool vis[N][N];
int sx,sy,gx,gy;
const int d1[4]={0,-1,0,1},d2[4]={1,0,-1,0};
long long ans;
void input_matrix(int (*a)[N])
{
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);
}
void update(int x,int y,int cur)
{
    if(sb[x][y]==-1)
           {
               ans+=on[x][y];
           }
           else
           {
               long long  tmp1=(long long )p[x][y]*(cur-sb[x][y]),tmp2=off[x][y]+on[x][y];
               ans+=tmp1>tmp2?tmp2:tmp1;
           }
           sb[x][y]=cur;
}
bool dfs(int x,int y,int cur)
{
  vis[x][y]=1;
  if(x==gx&&y==gy)
  {
    update(x,y,cur);
    return true;
  }
  for(int i=0;i<4;i++)
  {
      int tmpx=x+d1[i],tmpy=y+d2[i];
      if(tmpx<n&&tmpx>=0&&tmpy<m&&tmpy>=0&&!vis[tmpx][tmpy]&&g[tmpx][tmpy]=='.'&&dfs(tmpx,tmpy,cur+1))
      {
           update(x,y,cur);
           return true;
      }
  }
  return false;
}
int main()
{
//    cout << "Hello world!" << endl;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%s",g[i]);
        input_matrix(p);
        input_matrix(on);
        input_matrix(off);
        memset(sb,-1,sizeof(sb));
        ans=0;
        scanf("%d%d",&sx,&sy);
        int i=1;
        while(i<k)
        {
            memset(vis,0,sizeof(vis));
            scanf("%d%d",&gx,&gy);
            int tmp=sb[sx][sy]==-1?0:sb[sx][sy];
            dfs(sx,sy,tmp);
            sx=gx;
            sy=gy;
            i++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
              if(sb[i][j]!=-1)
              ans+=off[i][j];
        printf("%lld\n",ans);
    }
    return 0;
}