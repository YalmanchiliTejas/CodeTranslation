#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=1e3+10;
const uli mod=1e9+7;
uli f[2][mx];
uli g[mx][mx];
uli cmb[mx][mx];
int main(){
  cmb[0][0]=1;
  for(int i=1;i<mx;i++){
    cmb[i][0]=cmb[i][i]=1;
    for(int j=1;j<i;j++){
      cmb[i][j]=cmb[i-1][j]+cmb[i-1][j-1];
      if(cmb[i][j]>=mod)cmb[i][j]-=mod;
    }
  }
  int N,a,b,c,d;
  scanf("%d %d %d %d %d",&N,&a,&b,&c,&d);
  for(int l=1;l<=N;l++){
    g[0][l]=1;
    for(int n=l;n<=N;n+=l){
      g[n][l]=cmb[n-1][l-1]*g[n-l][l]%mod;
    }
  }
  int rw=0;
  f[rw][0]=1;
  for(int l=a;l<=b;l++){
    rw^=1;
    f[rw][0]=1;
    for(int n=1;n<=N;n++){
      f[rw][n]=f[rw^1][n];
      int from=max(1,c);
      int to=min(n/l,d);
      for(int x=from;x<=to;x++){
        f[rw][n]+=f[rw^1][n-x*l]*g[l*x][l]%mod*cmb[n][l*x]%mod;
        if(f[rw][n]>=mod)f[rw][n]-=mod;
      }
    }
  }
  printf("%lld\n",f[rw][N]);
  return 0;
}
