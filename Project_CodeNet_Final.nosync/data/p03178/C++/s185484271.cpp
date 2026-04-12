#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>
#include <bitset>
#include <iterator>
#include <cmath>
#include <stack>
#include <random>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

constexpr ll mod = 1e9+7;
const double PI = acos(-1.0);
mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  int d; cin >> d;

  vector<vector<ll>> dp1(2, vector<ll>(d));
  vector<vector<ll>> dp2(2, vector<ll>(d));
  dp1[0][0] = 1;

  rep(i, s.size()) {
    int a = s[i] - '0';
    for(int j=0; j<a; j++) {
      rep(k, d) {
        dp2[1][(k+j)%d] += dp1[0][k];
        dp2[1][(k+j)%d] %= mod;
      }
    }
    rep(k, d) {
      dp2[0][(k+a)%d] += dp1[0][k];
    }
    rep(j, 10) {
      rep(k, d) {
        int r = (k+j)%d;
        dp2[1][r] += dp1[1][k];
        dp2[1][r] %= mod;
      }
    }
    rep(k, d) {
      dp1[0][k] = dp2[0][k];
      dp2[0][k] = 0;
      dp1[1][k] = dp2[1][k];
      dp2[1][k] = 0;
    }
  }

  ll ans = dp1[0][0] + dp1[1][0] + mod - 1;
  ans %= mod;

  cout << ans << endl;
}
