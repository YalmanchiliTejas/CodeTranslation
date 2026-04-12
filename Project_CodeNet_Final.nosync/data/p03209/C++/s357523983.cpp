#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vl>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

vl burger, patty;

ll dfs(ll &X, int L) {
  ll ret = 0;

  // bun
  --X;
  if (X == 0) return ret;

  // level L-1 burger
  if (X < burger[L-1]) return ret + dfs(X, L-1);
  X -= burger[L-1];
  ret += patty[L-1];
  if (X == 0) return ret;

  // patty
  --X;
  ++ret;
  if (X == 0) return ret;

  // level L-1 burger
  if (X < burger[L-1]) return ret + dfs(X, L-1);
  X -= burger[L-1];
  ret += patty[L-1];
  return ret;  // left only buns
}

void solve() {
  int N; ll X; cin >> N >> X;

  burger.assign(N+1, 1);
  patty.assign(N+1, 1);
  rep(i,N) {
    burger[i+1] = burger[i]*2 + 3;
    patty[i+1] = patty[i]*2 + 1;
  }

  cout << dfs(X, N) << endl;
}

int main() {
  solve();
  return 0;
}
