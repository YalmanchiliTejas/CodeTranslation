#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()

using ull = unsigned long long;

void fail() {
  cout << -1 << endl;
  exit(0);
}

int f(ull x, int k) {
  return x >> k & 1;
}

void on(ull &x, int k) {
  x |= 1ULL << k;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N; cin >> N;
  vector<ull> S(N), T(N), U(N), V(N);
  rep(i, N) cin >> S[i];
  rep(i, N) cin >> T[i];
  rep(i, N) cin >> U[i];
  rep(i, N) cin >> V[i];
  vector<vector<ull>> ans(N, vector<ull>(N));
  auto row_or = [&](int i) {
    ull res = 0;
    rep(j, N) res |= ans[i][j];
    return res;
  };
  auto row_and = [&](int i) {
    ull res = ULLONG_MAX;
    rep(j, N) res &= ans[i][j];
    return res;
  };
  auto col_or = [&](int j) {
    ull res = 0;
    rep(i, N) res |= ans[i][j];
    return res;
  };
  auto col_and = [&](int j) {
    ull res = ULLONG_MAX;
    rep(i, N) res &= ans[i][j];
    return res;
  };
  rep(k, 64) {
    vector<vector<bool>> used(N, vector<bool>(N));
    // 論理積が1
    rep(i, N) rep(j, N) {
      if ((S[i] == 0 and f(U[i], k) == 1) or (T[j] == 0 and f(V[j], k) == 1)) {
        if (used[i][j] and f(ans[i][j], k) != 1) fail();
        used[i][j] = true;
        on(ans[i][j], k);
      }
    }
    // 論理和が0
    rep(i, N) rep(j, N) {
      if ((S[i] == 1 and f(U[i], k) == 0) or (T[j] == 1 and f(V[j], k) == 0)) {
        if (used[i][j] and f(ans[i][j], k) != 0) fail();
        used[i][j] = true;
      }
    }
    // 論理和が1
    rep(i, N) rep(j, N) {
      if ((S[i] == 1 and f(U[i], k) == 1) and (T[j] == 1 and f(V[j], k) == 1)) {
        used[i][j] = true;
        on(ans[i][j], k);
      }
    }
    vector<int> row1, col1, row0, col0;
    rep(i, N) {
      if (S[i] == 1 and f(U[i], k) == 1 and f(row_or(i), k) == 0) row1.push_back(i);
      if (T[i] == 1 and f(V[i], k) == 1 and f(col_or(i), k) == 0) col1.push_back(i);
      if (S[i] == 0 and f(U[i], k) == 0) row0.push_back(i);
      if (T[i] == 0 and f(V[i], k) == 0) col0.push_back(i);
    }
    if (not col0.empty()) {
      int j = 0;
      for (int i : row1) {
        on(ans[i][col0[j]], k);
        j++;
        j %= col0.size();
      }
    }
    if (not row0.empty()) {
      int i = 0;
      for (int j : col1) {
        on(ans[row0[i]][j], k);
        i++;
        i %= row0.size();
      }
    }
  }
  rep(i, N) {
    if (S[i] == 0 and row_and(i) != U[i]) fail();
    if (S[i] == 1 and row_or(i) != U[i]) fail();
    if (T[i] == 0 and col_and(i) != V[i]) fail();
    if (T[i] == 1 and col_or(i) != V[i]) fail();
  }
  rep(i, N) rep(j, N) cout << ans[i][j] << " \n"[j == N - 1];
}