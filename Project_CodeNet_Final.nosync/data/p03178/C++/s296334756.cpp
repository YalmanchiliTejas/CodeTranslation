#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[100010][110][2];

int main(){
  string s; cin >> s;
  int n=s.size();
  int D; cin >> D;
  dp[0][0][0]=1;
  rep(i,n){
    rep(j,D){
      int ni=i+1;
      rep(d,10){
        int nj=(j+d%D)%D;
        if(d>s[i]-'0'){
          dp[ni][nj][1]+=dp[i][j][1];
        }
        else if(d<s[i]-'0'){
          dp[ni][nj][1]+=dp[i][j][0];
          dp[ni][nj][1]+=dp[i][j][1];
        }
        else{
          dp[ni][nj][1]+=dp[i][j][1];
          dp[ni][nj][0]+=dp[i][j][0];
        }
        dp[ni][nj][1]%=mod;
        dp[ni][nj][0]%=mod;
      }
    }
  }
  ll ans=(dp[n][0][0]+dp[n][0][1])%mod;
  ans--;
  if(ans<0) ans+=mod;
  cout << ans << endl;
}