#include <cstdio>
#include <cstring>
const int maxn=10;
int n,m;
char pic[maxn][maxn];
int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
inline bool dfs(int sx,int sy){
  int cnt=0;
  int tx=-1,ty=-1;
  pic[sx][sy]='.';
  for(int k=0,nx,ny;k<4;k++){
    nx=sx+next[k][0];
	ny=sy+next[k][1];
	if(pic[nx][ny]=='#'){
	  cnt++;
	  if(k<=1)
	    tx=nx,ty=ny;
	}
  }
  if(sx==n&&sy==m&&cnt==0)return 1;
  if(sx==n&&sy==m)return 0;
  if(cnt!=1)return 0;
  return dfs(tx,ty);
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
	scanf("%s",pic[i]+1);
  if(dfs(1,1))printf("Possible");
  else printf("Impossible");
  return 0;
}
