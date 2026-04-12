#include <bits/stdc++.h> 

using namespace std; //ごめんなさい
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  vector<int>dp(N,-1);
  for(int i=0;i<N;i++){
    int l=-1,r=N,m;
    while(r-l>1){
      m=(r+l)/2;
      if(dp[m]>=A[i])l=m;
      else r=m;
    }
    dp[r]=max(A[i],dp[r]);
    dp[0]=max(dp[0],A[i]);
  }
  ll ans=0;
  for(int i=0;i<N;i++)if(dp[i]!=-1)ans=i;
  cout<<ans+1<<endl;
  return 0;
}
