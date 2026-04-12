#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
#define rep(i, ne) for (int i = 0; i < ne; ++i)

int N;
vector<ull> a, b;

void input() {
  cin >> N;
  a.resize(N);
  b.resize(N + 1);
  rep(i, N) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }
}

void solve() {
  ull ans = 0;
  ull tmp;
  rep(i, N) {
    tmp = (b[N] - b[i + 1]) % MOD;
    tmp = (a[i] * tmp) % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  input();
  solve();
  getchar();
  return 0;
}