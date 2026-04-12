#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=998244353;
const int inf=1<<30;

ll dp[3010][3010];

int main(){
  int n,s; cin >> n >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll ans=0;
  rep(i,n+1) dp[i][0]=1;
  rep(i,n)rep(j,s){
    if(j+a[i]<=3009) dp[i+1][j+a[i]]+=dp[i][j];
    dp[i+1][j]+=dp[i][j];
    dp[i+1][j+a[i]]%=mod;
    dp[i+1][j]%=mod;
  }
  rep(i,n+1){
    ans+=dp[i][s]*(n-i+1)%mod;
    ans%=mod;
  }
  /*
  rep(i,n+1){
    rep(j,s+1){
      cout << dp[i][j];
    }cout << endl;
  }*/
  cout << ans << endl;
}