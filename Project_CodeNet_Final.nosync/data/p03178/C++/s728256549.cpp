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
      rep(k,2){
        int ni=i+1;
        //ここに置くミス
        rep(d,10){
          int nk=k;//これを↑
          if(k==0){
            if(d>int(s[i]-'0')) continue;
            if(d<int(s[i]-'0')) nk=1;
          }
          int nj=(j+d%D)%D;
          dp[ni][nj][nk]+=dp[i][j][k];
          dp[ni][nj][nk]%=mod;
        }
      }
    }
  }
  ll ans=(dp[n][0][0]+dp[n][0][1])%mod;
  ans--;
  if(ans<0) ans+=mod;
  cout << ans << endl;
}