#ifdef ONLINE_JUDGE
  #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif

#include "bits/stdc++.h"
using namespace std;
#define int long long

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

vector<int> v; int d;
const int mod = 1e9 + 7;
int pre[2][101][10001];
bool vis[2][101][10001];
int dp(bool f, int remainder, int pos) {
  if (vis[f][remainder][pos]) return pre[f][remainder][pos];
  vis[f][remainder][pos] = true;
  if (pos == v.size()) {
    return pre[f][remainder][pos] = remainder == 0;
  }
  int x = 0;
  for (int r = 0; r <= (f ? 9 : v[pos]); r ++) {
    x = (x + dp(f || (r < v[pos]), (remainder + r) % d, pos + 1)) % mod;
  }
  return pre[f][remainder][pos] = x;
}

signed main() {
  #ifndef ONLINE_JUDGE
    ifstream cin("in");
  #endif
  ios_base::sync_with_stdio(0); cin.tie(0); // harris leung ioi gold calling it 18.09

  string s; cin >> s >> d;
  for (char c : s) v.push_back(c - '0');
  cout << (dp(0, 0, 0) + mod - 1) % mod << endl;
}