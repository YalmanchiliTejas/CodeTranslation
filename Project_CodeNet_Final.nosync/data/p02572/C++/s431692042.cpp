#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
  int n;
  cin >> n;

  ll sum = 0, square = 0;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum = (sum + a[i]) % mod;
    square = (square + a[i] * a[i]) % mod;
  }

  ll ans = ((sum * sum) % mod - square + mod) % mod;
  if (ans < 0) ans += mod;

  ll inv_2 = modinv(2, mod);

  cout << (ans * inv_2) % mod << endl;
}
