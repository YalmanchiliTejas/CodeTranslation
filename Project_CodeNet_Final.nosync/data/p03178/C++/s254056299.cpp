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

int dp[100001][101][2];

int main(){
  string s; int m; cin >> s >> m;
  int n=s.size();
  dp[0][0][0]=1;
  rep(i,n)rep(j,m)rep(k,2){
    int nd=s[i]-'0';
    int nk;
    rep(d,10){
      int nj=(j+d)%m;
      if(d>nd){
        if(k==0) continue;
        if(k==1) nk=1;
      }
      if(d==nd){
        if(k==0) nk=0;
        if(k==1) nk=1;
      }
      if(d<nd) nk=1;
      dp[i+1][nj][nk]+=dp[i][j][k];
      dp[i+1][nj][nk]%=mod;
    }
  }
  ll ans=dp[n][0][0]+dp[n][0][1];
  ans--;
  if(ans<0) ans+=mod;
  cout << ans << endl;
}