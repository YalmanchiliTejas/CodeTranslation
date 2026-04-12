#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<int,int> P;

int dp[105][4][2];

int main(){
  string s;
  cin >> s;
  int K;
  cin >> K;
  int n=s.size();
  dp[0][0][0]=1;
  rep(i,n)rep(j,K+1)rep(k,2){
    int nd = s[i]-'0';
    rep(d,10){
      int ni = i+1;
      int nj = j;
      int nk = k;
      if(d!=0)nj++;
      if(nj>K)continue;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk]+=dp[i][j][k];
    }
  }
  cout << dp[n][K][1]+dp[n][K][0] << endl;
}
