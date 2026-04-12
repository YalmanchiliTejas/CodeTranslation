#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[100005][105][2];

int main() {
  int D; string s;
  cin >> s >> D;
  int n=s.size();
  dp[0][0][0]=1ll;
  rep(i,n)rep(j,D)rep(k,2){
    int nd=s[i]-'0';
    rep(d,10){
      int ni=i+1,nj=j,nk=k;
      nj=(nj+d)%D;
      if(k==0){
        if(d>nd) continue;
        if(d<nd) nk=1;
      }
      dp[ni][nj][nk]+=dp[i][j][k];
      dp[ni][nj][nk]%=mod;
    }
  }
  ll ans=(dp[n][0][0]+dp[n][0][1])%mod;
  ans--;
  if(ans<0) ans+=mod;
  cout << ans << endl;
}
