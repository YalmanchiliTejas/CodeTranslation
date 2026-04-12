#include <bits/stdc++.h>
using namespace std;

// #undef LOCAL
#ifdef LOCAL
#include "../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

vector<ll> all;
vector<ll> pate;

ll dfs(int N, ll X)
{
  ll ans = 0;
  dump(N, X);
  if (N == 0)
    return 1;
  if (X > 0) {
    X--;
  }
  if (X > 0) {
    if (all[N - 1] <= X) {
      ans += pate[N - 1];
      X -= all[N - 1];
    } else {
      ans += dfs(N - 1, X);
      X = 0;
    }
  }
  if (X > 0) {
    ans++;
    X--;
  }
  if (X > 0) {
    if (all[N - 1] <= X) {
      ans += pate[N - 1];
      X -= all[N - 1];
    } else {
      ans += dfs(N - 1, X);
      X = 0;
    }
  }
  if (X > 0) {
    X--;
  }
  dump(ans);
  return ans;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  // freopen("d.1", "r", stdin);
  int N;
  ll X;
  cin >> N >> X;
  all.resize(N + 1);
  pate.resize(N + 1);
  all[0] = 1;
  pate[0] = 1;
  for (int i = 1; i <= N; i++) {
    all[i] = all[i - 1] * 2 + 3;
    pate[i] = pate[i - 1] * 2 + 1;
  }
  dumpv(all);
  dumpv(pate);
  cout << dfs(N, X) << endl;
  return 0;
}