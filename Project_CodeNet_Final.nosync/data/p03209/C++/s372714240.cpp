#include "bits/stdc++.h"

#define rep(i, a) for (int i = 0; i < (a); ++i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define vi vector<int>

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cerr << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << endl
#define debug_4(x1, x2, x3, x4) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5) cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define debug(...) CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) (__VA_ARGS__)

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 100005;

ll num[51];
ll paty[51];

ll f(int L, ll x) {
  if (L == 0) return 1;
  if (x == 1) return 0;
  if (x == num[L]/2) return paty[L]/2;
  if (x == num[L]/2 + 1) return paty[L]/2 + 1;
  if (x == num[L] || x == num[L] - 1) return paty[L];
  if (x > num[L]/2+1) return paty[L]/2+1+f(L-1, x - num[L]/2 - 1);
  return f(L-1, x-1);
}

void Main() {
  int n; ll x;
  cin >> n >> x;
  num[0] = 1;
  rep(i, n) num[i+1] = num[i]*2 + 3;
  paty[0] = 1;
  rep(i, n) paty[i+1] = paty[i]*2 + 1;
  cout << f(n, x) << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
