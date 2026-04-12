#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=998244353;
const int inf=1<<30;
  
ll dp[3010][3010];

int main(){
  int n,s; cin >> n >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n)rep(j,s){
	if(j==0&&a[i]<=s) {dp[i+1][a[i]]+=i+1; dp[i+1][a[i]]%=mod;}
    else if(dp[i][j]>0){
      dp[i+1][j]+=dp[i][j]; dp[i+1][j]%=mod;
      if(j+a[i]<=s) {dp[i+1][j+a[i]]+=dp[i][j]; dp[i+1][j+a[i]]%=mod;}
    }
  }
  ll ans=0;
  rep(i,n+1){
    ans+=dp[i][s]*(n-i+1)%mod;
    ans%=mod;
  }
  cout << ans << endl;
}