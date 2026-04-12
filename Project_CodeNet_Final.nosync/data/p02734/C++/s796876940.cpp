/**
 *     author: qodjf
 *     created: 04.29.2020 02:19:55
 */
#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define mst(x, a) memset(x, a, sizeof(x))

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;

ll mul(ll a, ll b) { return a * b % MOD; }

ll add(ll a, ll b) { return (a + b) % MOD; }

ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }

int N, S;
vector<int> A;

void solve() {
  vector<vector<ll>> dp(N + 1, vector<ll>(S + 1, 0));
  dp[1][0] = 1;
  if (A[0] <= S) {
    dp[1][A[0]] = 1;
  }
  for (int i = 2; i <= N; i++) {
    int a = A[i - 1];
    for (int s = 0; s <= S; s++) {
      dp[i][s] = 2 * dp[i - 1][s] - dp[i - 2][s];
      if (s >= a) {
        dp[i][s] += dp[i - 1][s - a] - dp[i - 2][s - a];
      }
      if (s == 0 || s == a) dp[i][s]++;
      dp[i][s] %= MOD;
    }
  }
  cout << (dp[N][S] % MOD + MOD) % MOD << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  solve();
}
