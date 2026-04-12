#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;

vector<ll> P(51, 0);

void initP(int n) {
  if (n == 0) return;
  if (P[n - 1] == 0) initP(n - 1);
  P[n] = 2 * P[n - 1] + 1;
  return;
}

ll calc(ll n, ll x) {
  if (n == 0) return 0;
  if (x == 0) return 0;

  if (n == 1) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3) return 3;
    if (x == 4) return 3;
  }

  ll m = pow(2, n + 1) - 2;
  if (x == m - 1) return P[n - 1];
  if (x == m) return P[n - 1] + 1;

  if (x < m) return calc(n - 1, x - 1);
  if (x == 2 * m) return 2 * P[n - 1] + 1;

  return P[n - 1] + 1 + calc(n - 1, x - (pow(2, n + 1) - 1));
}

int main() {
  ll N, X;
  cin >> N >> X;

  P[0] = 1;
  initP(50);

  std::cout << calc(N, X - 1) << "\n";
  return 0;
}