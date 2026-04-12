#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <tuple>
#include <functional>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <random>
#include <stack>

using namespace std;

#define endl '\n'

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using lld = long double;
using ull = unsigned long int;
using ll = long long;

void solve() {
  string s; cin >> s;
  int D; cin >> D;
  ll mod = 1e9 + 7;
  vector<vector<ll>> dp0(s.size() + 1, vector<ll>(D, 0));
  vector<vector<ll>> dp1(s.size() + 1, vector<ll>(D, 0));

  dp0[0][0] = 1;
  for (int i = 1; i <= (int) s.size(); ++i) {
    for (int v = 0; v < D; ++v) {
      dp1[i][v] = 0;
      int cur = s[i-1] - '0';
      int ss = (v - cur + 10 * D) % D;
      dp0[i][v] = dp0[i-1][ss];
      for (int d = 0; d < 10; ++d) {
        int sum = (v - d + 10 * D) % D;
        dp1[i][v] = (dp1[i][v] + dp1[i-1][sum]) % mod;
        if (d < cur) {
          dp1[i][v] = (dp1[i][v] + dp0[i-1][sum]) % mod;
        }
      }
    }
  }
  int n = s.size();
  cout << (dp1[n][0] + dp0[n][0] - 1 + mod) % mod << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int precision = 13;
  cout.precision(precision);
  cout.setf(ios_base::fixed);

  solve();

  return 0;
}