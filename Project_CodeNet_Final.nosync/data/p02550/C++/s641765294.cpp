#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (ll i = ss; i < ee; ++i)

ll N, X, M;
void input() { cin >> N >> X >> M; }

void solve() {
  ll sum = 0;
  ll len = 0;
  vector<ll> v;
  vector<ll> id(M, -1);

  while (id[X] == -1) {
    id[X] = len;
    v.emplace_back(X);
    sum += X;
    len++;
    // cout << X << " " << len << " " << sum << endl;
    X = (X * X) % M;
  }

  ll c = len - id[X];
  ll sum_c = 0;
  rep(i, id[X], len) { sum_c += v[i]; }
  // cout << "cycle" << c << " sum_c" << sum_c << endl << endl;

  ll ans = 0;
  if (N <= len) {
    // Nが周期以下
    rep(i, 0, N) { ans += v[i]; }

  } else {
    //周期に入るまで
    ans += sum;

    //周期合計ｘ周期回数
    N -= len;
    ans += sum_c * (N / c);

    // 周期終わった後の残り
    N %= c;
    rep(i, 0, N) ans += v[id[X] + i];
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}

// 10000000000 10 99959
// 492443256176507