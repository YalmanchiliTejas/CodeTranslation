#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

ll count(ll N, ll X, vl &xCount, vl &pCount) {
  if (X == 0) {
    return 0;
  }

  if (X == xCount[N]) {
    return pCount[N];
  }

  ll middle = (xCount[N] + 1) / 2;
  if (middle > X) {
    return count(N - 1, X - 1, xCount, pCount);
  } else {
    return 1 + count(N - 1, middle - 2, xCount, pCount) +
           count(N - 1, X - middle, xCount, pCount);
  }
}

void solve(long long N, long long X) {
  vl xCount(N + 1);
  vl pCount(N + 1);

  xCount[0] = 1;
  pCount[0] = 1;
  rep(n, 1, N + 1) {
    xCount[n] = 3 + 2 * xCount[n - 1];
    pCount[n] = 1 + 2 * pCount[n - 1];
  }

  print(count(N, X, xCount, pCount));
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long X;
  scanf("%lld", &X);
  solve(N, X);
  return 0;
}
