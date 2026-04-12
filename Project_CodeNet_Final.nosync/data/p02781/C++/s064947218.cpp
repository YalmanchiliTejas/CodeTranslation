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
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;
int dp[105][4][2]; // i桁数, jが0でない個数 ,kが0で完全に一致

int main(){
  string s;
  cin >> s;
  int n, K;
  cin >> K;
  n = s.size();
  dp[0][0][0] = 1;
  rep(i, n)rep(j, 4)rep(k, 2) {
    int nd = s[i] - '0';
    rep(d, 10) {
      int ni = i + 1, nj = j, nk = k;
      if(d != 0) ++nj;
      if(nj > K) continue;
      if(k == 0) {
        if(d > nd) break;
        if(d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
}
