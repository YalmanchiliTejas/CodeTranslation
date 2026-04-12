#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll dp[3030][3030];
int N; 
ll A[3030];
ll INF=LLONG_MAX/2;

ll solve(int l,int r){
  if(dp[l][r]!=INF) return dp[l][r];
  if(l==r) return (dp[l][r]=(N%2?1:-1)*A[l]);
  if(N%2!=(r-l)%2){
    ll L=solve(l+1,r)+A[l];
    ll R=solve(l,r-1)+A[r];
    return (dp[l][r]=max(L,R));
  }else{
    ll L=solve(l+1,r)-A[l];
    ll R=solve(l,r-1)-A[r];
    return (dp[l][r]=min(L,R));
  }
}

int main(){
  rep(i,3030) rep(j,3030) dp[i][j]=INF;
  cin>>N;
  rep(i,N) cin>>A[i];
  solve(0,N-1);
  cout<<dp[0][N-1]<<endl;
  return 0;
}
