#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<double, double>P;
typedef tuple<ll, int, int>T;
#define PI 3.14159265358979


int main(){
  int N;
  cin>>N;
  vector<ll>A(N);
  rep(i,N){cin>>A[i];}
  ll dp[3000][3000];
  rep(i,N){
    rep(j,N){
      dp[i][j]=0ll;
   }
  }
  //k=0だけ前もって入れとく
  if((N-1)%2==0){
    rep(i,N){
      dp[i][i]+=A[i];
    }
  }
  else{
    rep(i,N){
      dp[i][i]-=A[i];
    }
  }
  for(int k=1;k<N;k++){
  	if((N-k-1)%2==0){
      rep(i,N){
        int j=i+k;
        if(j>=N){continue;}
        	dp[i][j]=max(dp[i+1][j]+A[i],dp[i][j-1]+A[j]);
      }
    }
  	else{
      rep(i,N){
        int j=i+k;
        if(j>=N){continue;}
        	dp[i][j]=min(dp[i+1][j]-A[i],dp[i][j-1]-A[j]);
      }
    }
  }
  cout<<dp[0][N-1];
}