#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

const int N = 3000 + 7;
int n;
int s;
int a[N];
int cnt[N];
int sum[N];
int sol;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > s) {
      continue;
    }
    if (a[i] == s) {
      sol = add(sol, mul(i, n + 1 - i));
    } else {
      int val = s - a[i];
      sol = add(sol, mul(n + 1 - i, sum[val]));
    }
    for (int x = s - a[i]; x >= 1; x--) {
      cnt[x + a[i]] = add(cnt[x + a[i]], cnt[x]);
      sum[x + a[i]] = add(sum[x + a[i]], sum[x]);
    }
    cnt[a[i]] = add(cnt[a[i]], 1);
    sum[a[i]] = add(sum[a[i]], i);
  }
  cout << sol << "\n";

}
