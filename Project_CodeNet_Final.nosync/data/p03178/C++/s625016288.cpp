#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

ll dp[11000][110][2];

int main() {
  string s;
  getline(cin,s);
  int m;
  cin>>m;
  for(int i = 0; i < 11000; i++) for(int j = 0; j < 110; j++) {dp[i][j][0]=0LL;dp[i][j][1]=0LL;}
  dp[0][0][0]=1LL;
  int l = s.size();
  for(int i = 1; i <= l; i++) {
    int t = s[i-1]-'0';
    for(int j = 0; j < m; j++){
      for(int k = 0; k < 10; k++){
        if(k<t) dp[i][(j+k)%m][1]=(dp[i][(j+k)%m][1]+dp[i-1][j][0])%mod;
        if(k==t) dp[i][(j+k)%m][0]=(dp[i][(j+k)%m][0]+dp[i-1][j][0])%mod;
        dp[i][(j+k)%m][1]=(dp[i][(j+k)%m][1]+dp[i-1][j][1])%mod;
      }
    }
  }
  ll ans = (dp[l][0][0]+dp[l][0][1]-1)%mod;
  if(ans<0LL)ans+=mod;
  cout<<ans<<endl;
}
    