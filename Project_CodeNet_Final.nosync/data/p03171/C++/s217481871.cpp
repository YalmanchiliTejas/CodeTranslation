#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(long long i=0; i<x;i++)
#define mod 1000000007
#define INF 10000000000
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main(){
  ios::sync_with_stdio(false);
  
  int N;
  cin>>N;
  ll a[N];
  rep(i,N) cin>>a[i];  
  
  ll dp[N+1][N+1];
  dp[0][0]=0;
  
  rep(i,N){
    dp[i][i]=0;
  }
  
  for(int len=1;len<N+1;len++){
  	for(int i=0;i+len<N+1;i++){
      int j= len+i;
      
    	if((N-len)%2==0){
          
          dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
          
          
        }else {
     		dp[i][j]= min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
        }
    }
  }
  

  
  cout<<dp[0][N];
  
}