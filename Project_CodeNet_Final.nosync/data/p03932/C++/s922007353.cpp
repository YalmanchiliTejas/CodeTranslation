#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T> void chmin(T &a,T b){if(a>b) a=b;}
template<typename T> void chmax(T &a,T b){if(a<b) a=b;}

Int a[222][222];
Int dp[2][222][222][222];
signed main(){
  memset(a,0,sizeof(a));
  Int h,w;
  cin>>h>>w;
  for(Int i=0;i<h;i++)
    for(Int j=0;j<w;j++)
      cin>>a[i][j];
  
  memset(dp,-1,sizeof(dp));
  dp[0][0][0][0]=a[0][0];
  for(Int i=0;i<h;i++){
    for(Int l=0;l<w;l++){
      for(Int r=l;r<w;r++){
	for(Int k=0;k<2;k++){
	  if(dp[k][i][l][r]<0) continue;
	  if(l+1<=r)
	    chmax(dp[k][i][l+1][r],dp[k][i][l][r]+(!k)*(l+1<r)*a[i][l+1]);
	  if(r+1<w)
	    chmax(dp[1][i][l][r+1],dp[k][i][l][r]+a[i][r+1]);
	  
	  chmax(dp[0][i+1][l][r],dp[k][i][l][r]+a[i+1][l]+(l!=r)*a[i+1][r]);
	}
      }
    }
  }
  cout<<max(dp[0][h][w-1][w-1],dp[1][h][w-1][w-1])<<endl;
  return 0;
}
