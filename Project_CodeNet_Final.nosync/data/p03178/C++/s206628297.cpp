#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

#define rep(i, a, b) for(auto i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back

struct edge{int to;};
using graph = vector<vector<edge>>;

const int MOD = 1000000007;
const int MAXD = 10000;
const int MAXK = 100;
ll dp[MAXD + 5][MAXK][2]; // # digits, modulo, isbelow

void add(auto& a, auto b){a = (a + b) % MOD;}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = sz(s);

  dp[0][0][0] = 1;
  rep(i, 0, n) {
    rep(j, 0, k) {
      rep(c, '0', '9' + 1) {
	int v = c - '0';
	int j2 = (j + v) % k;
	add(dp[i + 1][j2][1], dp[i][j][1]);
	
	if (c < s[i]) {
	  add(dp[i + 1][j2][1], dp[i][j][0]);
	}
	else if (c == s[i]) {
	  add(dp[i + 1][j2][0], dp[i][j][0]);
	}
      }
    }
  }
  cout << (dp[n][0][1] + dp[n][0][0] - 1 + MOD) % MOD << '\n'; // zero is not valid answer
}
