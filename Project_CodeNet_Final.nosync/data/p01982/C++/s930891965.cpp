#include <bits/stdc++.h>

using namespace std;

#define reps(i, n, m) for (int i = (int) (n); i < (int) (m); i++)
#define rep(i, n) reps(i, 0, n)

int n, l, r;
vector<int> a;

bool init() {
  a.clear();
  cin >> n >> l >> r;
  if (n == 0) return false;
  a.resize(n);
  rep(i, n) {
    cin >> a[i];
  }
  return true;
}

int check(int x) {
  rep(i, n) {
    if (x % a[i] == 0) {
      return 1 - i % 2;
    }
  }
  return 1 - n % 2;
}


void solve() {
  int res = 0;
  reps(i, l, r+1) {
    res += check(i);
  }
  cout << res << endl;
}

int main() {
    while (init()) {
        solve();
    }
}
