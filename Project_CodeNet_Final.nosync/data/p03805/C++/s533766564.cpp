#include <stdio.h>
using namespace std;
int n,m,i,j,k;
int a[100],b[100];
bool g[100][100];
bool f[10];

int dfs(int num,bool flg []){
  int i;
  int ans=0;
  bool flg2[10];
  bool fl=true;
  for (i=0;i<n;i++){
    flg2[i]=flg[i];
    if (!flg2[i]){fl=false;}
  }
  if (fl){return 1;}
  for (i=0;i<n;i++){
    if (!flg2[i] && g[num][i]){
        flg2[i]=true;
        ans+=dfs(i,flg2);
        flg2[i]=false;

    }
  }
  return ans;

}

int main(){
  scanf("%d %d",&n,&m);
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      g[i][j]=false;
    }
  }
  for (i=0;i<m;i++){
    int t0,t1;
    scanf("%d %d",&t0,&t1 );
    g[t0-1][t1-1]=true;
    g[t1-1][t0-1]=true;
  }
  for (i=0;i<n;i++){f[i]=false;}
  f[0]=true;
  int ans=dfs(0,f);
  printf("%d\n",ans );
}
