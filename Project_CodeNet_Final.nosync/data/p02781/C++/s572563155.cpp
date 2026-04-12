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

ll dp[110][4][2];

int main() {
  string s; cin >> s;
  int K; cin >> K;
  int n=s.size();
  dp[0][0][0]=1ll;
  rep(i,n)rep(j,n+1)rep(k,2){
    rep(d,10){
      int ni=i+1,nj=j,nk=k;
      if(d!=0) nj++;
      if(nj>K) continue;
      if(k==0){
        if(d>s[i]-'0') continue;
        if(d<s[i]-'0') nk=1;
      }
      dp[ni][nj][nk]+=dp[i][j][k];
    }
  }
  cout << dp[n][K][0]+dp[n][K][1] << endl;
}
