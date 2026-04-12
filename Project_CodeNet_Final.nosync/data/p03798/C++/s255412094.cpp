#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int left(int x, int n) {
  x--;
  if (x == -1) x = n - 1;
  return x;
}

int right(int x, int n) {
  x++;
  if (x == n) x = 0;
  return x;
}

// sheep is one
// wolf is zero

int modify(int &a, int &b, int i, int c) {
  if (i == 0) c = 1 - c;
  if (a == -1) {
    if (c) a = b;
    else a = 1 - b;
  }
  else if (b == -1) {
    if (c) b = a;
    else b = 1 - a;
  }
  else {
    if ((a == b) != c) return 1;
  }
  return 0;
}

void sol(string s, int n, int sto, int stt) {
  vector<int> a(n, -1);
  a[0] = sto;
  a[1] = stt;
  for (int i = 0; i < n; i++) {
    if (modify(a[left(i, n)], a[right(i, n)], a[i], (s[i] == 'o'))) {
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (a[i] ? "S" : "W");
  }
  cout << '\n';
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i <= 1; i++)
  for (int j = 0; j <= 1; j++) {
    sol(s, n, i, j);
  }
  cout << -1 << '\n';
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
