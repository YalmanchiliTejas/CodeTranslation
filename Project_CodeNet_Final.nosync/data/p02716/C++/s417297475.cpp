#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << endl; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "abc162_f.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int m = n / 2;
  vl a(n);
  REP(i, n) { cin >> a[i]; }

  if (n % 2 == 0) {
    vector<ll> left(m, -1e10), right(m, -1e10);
    left[0] = a[0];
    right[0] = a[1];
    FOR(i, 1, m) {
      left[i] = left[i - 1] + a[2 * i];
      right[i] = max(right[i - 1], left[i - 1]) + a[2 * i + 1];
    }
    cout << max(left[m - 1], right[m - 1]) << endl;
  } else {
    vector<ll> left(m, -1e10), right(m, -1e10), center(m, -1e10);
    left[0] = a[0];
    center[0] = a[1];
    right[0] = a[2];

    FOR(i, 1, m) {
      left[i] = left[i - 1] + a[2 * i];
      center[i] = max(left[i - 1], center[i - 1]) + a[2 * i + 1];
      right[i] = max({left[i - 1], center[i - 1], right[i - 1]}) + a[2 * i + 2];
    }
    cout << max({left[m - 1], center[m - 1], right[m - 1]}) << endl;
  }
}
