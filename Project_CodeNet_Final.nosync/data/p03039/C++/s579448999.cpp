#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
template<class T> inline void YES(T condition) { 
    if(condition) cout << "YES" << endl;
    else cout << "NO" << endl;
}
template<class T> inline void Yes(T condition) {
    if(condition) cout << "Yes" << endl;
    else cout << "No" << endl;
}
template<class T> T gcd(T a, T b) {
    while (b) {
        T tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
template<class T> T lcm(T a, T b){
    return a / gcd(a, b) * b;
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

long long qpow(long long a, long long b, int MOD) {
    if (b == 0) return 1;
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

const int MOD = 1e9 + 7;
const int maxn = 2e6;
int fac[maxn + 5];
int invfac[maxn + 5];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= maxn; i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
    invfac[maxn] = (int)(qpow(fac[maxn], MOD - 2, MOD));
    for (int i = maxn - 1; i >= 0; i--) invfac[i] = 1LL * invfac[i + 1] * (i + 1) % MOD;
}
int C(int n, int k) {
    assert(0 <= k && n >= k);
    int tmp = (int)(1LL * invfac[k] * invfac[n - k] % MOD);
    return (int)(1LL * fac[n] * tmp % MOD);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    init();
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        int d = n - 1 - i;
        LL cur = 1LL * d * (d + 1) / 2;
        cur = (cur * m) % MOD;
        cur = (cur * m) % MOD;
        ans = (ans + cur) % MOD;
    }
    for (int j = 0; j < m; j++) {
        int d = m - 1 - j;
        LL cur = 1LL * d * (d + 1) / 2;
        cur = (cur * n) % MOD;
        cur = (cur * n) % MOD;
        ans = (ans + cur) % MOD;
    }
    ans = (ans * C(n * m - 2, k - 2)) % MOD;
    cout << ans << '\n';

    return 0;
}
