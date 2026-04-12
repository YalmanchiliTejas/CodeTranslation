#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
bool custom1 (pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first);
}
bool custom2(pair<int, int> a, pair<int, int> b) {
  return (a.second < b.second);
}

const int MAX = 200005;
const long long MOD = 1000000007;
const long long MODMOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
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

long long gcd(long long a, long long b) {
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> ans_1;
  vector<ll> ans_2;
  ans_1.emplace_back(a[0]);
  ans_2.emplace_back(a[n-1]);
  ll ans = a[n-1] - a[0];
  int left = 1;
  int right = n-2;
  rep(i, n-2) {
    ll p = abs(a[left]-ans_1.back());
    ll q = abs(a[left]-ans_2.back());
    ll r = abs(a[right]-ans_1.back());
    ll s = abs(a[right]-ans_2.back());
    vector<ll> candidate({p, q, r, s});
    ll t = *max_element(candidate.begin(), candidate.end());
    ans += t;
    if(p == t) {
      ans_1.emplace_back(a[left]);
      left++;
    }
    else if(q == t) {
      ans_2.emplace_back(a[left]);
      left++;
    }
    else if(r == t) {
      ans_1.emplace_back(a[right]);
      right--;
    }
    else if(s == t) {
      ans_2.emplace_back(a[right]);
      right--;
    }
  }

  cout << ans << endl;
}
