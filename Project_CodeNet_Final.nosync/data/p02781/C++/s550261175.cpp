#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;
int dp[110][5][2];

int main() {
  string s;
  int K;
  cin >> s >> K;
  int n = s.length();
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 4) rep(k, 2) rep(l, 10) {
    int ni = i + 1, nj = j, nk = k;
    if(l != 0) nj++;
    if(nj > K) continue;
    if(nk == 0) {
      if(l < s[i] - '0') dp[ni][nj][1] += dp[i][j][k];
      else if(l == s[i] - '0') dp[ni][nj][0] += dp[i][j][k];
      else break;
    } else if (nk == 1) {
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  cout << dp[n][K][0] + dp[n][K][1] << endl;
}