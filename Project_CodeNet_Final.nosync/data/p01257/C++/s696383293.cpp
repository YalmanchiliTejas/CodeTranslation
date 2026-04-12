#include<iostream>
using namespace std;
#define N 100001
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

int table[10][N];
int dp(int n,int m,int *coin,int lim){
  rep(i,m+1){
    if ( i%coin[0]==0)table[0][i]=i/coin[0];
    else table[0][i]=lim+1;
  }
  
  REP(i,1,n){
    rep(j,coin[i]){
      if ( table[i-1][j]>lim){
	table[i][j]=lim+1;
      }else table[i][j]=0;
    }
    
    REP(j,coin[i],m+1){
      if ( table[i-1][j]>lim){
	if ( table[i][j-coin[i]]>lim)table[i][j]=lim+1;
	else table[i][j]=table[i][j-coin[i]]+1;
      }
      else table[i][j]=0;
    }    
  }
  
  return table[n-1][m]<=lim?true:false;
}

int solve(int n,int m,int *coin){
  int l=1,r=m,ret=m,mid;
  while(l<=r){
    mid =(l+r)/2;
    if ( dp(n,m,coin,mid)==false)l=mid+1;
    else {
      ret=mid;
      r=mid-1;
    }

  }

  return ret;
}

main(){
  int n,m;
  while(cin>>n>>m&&n){
    int coin[n];
    rep(i,n)cin>>coin[i];
    cout << solve(n,m,coin) << endl;
  }
}