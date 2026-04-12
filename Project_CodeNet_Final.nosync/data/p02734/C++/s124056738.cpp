#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll dp[3001][3001][3];

ll Solve(int at, int have, int state, const vector<int>& a, int s) {
  if (at == a.size()) {
    if (have == s && state == 2) return 1;
    return 0;
  }

  if (have > s) return 0;

  ll& result = dp[at][have][state];
  if (result != -1) return result;

  result = 0;

  if (state == 0) {
    result = Solve(at + 1, have, state, a, s) + Solve(at, have, state + 1, a, s);
    result %= mod;
  }

  if (state == 1) {
    result = Solve(at + 1, have, state, a, s) + Solve(at + 1, have + a[at], state, a, s) + Solve(at, have + a[at], state + 1, a, s) + Solve(at, have, state + 1, a, s);
    result %= mod;
  }

  if (state == 2) {
    result = Solve(at + 1, have, state, a, s);
  }

  return result;
}

int main()
{
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  memset(dp, -1, sizeof(dp));
  cout << Solve(0, 0, 0, a, s) << endl;

  return 0;
}
