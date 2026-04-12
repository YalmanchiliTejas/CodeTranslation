#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

constexpr int INF = 1e9;
constexpr ll BIGINF = 1e18;
constexpr double EPS = 1e-16;
constexpr int MOD = 1e9 + 7;

void preambule() {
  cin.tie(0);
  cout.precision(16);
  cout << fixed;
}

string s;

void input() {
  cin >> s;
}

void solve() {
  string ans = "Yes";

  if ((int)s.find("AB") * (int)s.find("BA") > 0)
    ans = "No";

  cout << ans << '\n';
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  preambule();

  int t = 1;

#ifdef _DEBUG
  t = 3;
#endif

  //  cin >> t;

  while (t--) {
    input();
    solve();
  }
}