#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;

struct mint {
   ll x;
   mint(ll x = 0) { (this->x = (x + MOD)) %= MOD; }
   mint operator-() const { return mint(-x); }
   mint& operator+=(const mint a) {
      if ((this->x += a.x) >= MOD) x -= MOD;
      return *this;
   }
   mint& operator-=(const mint a) {
      if ((this->x += MOD - a.x) >= MOD) this->x -= MOD;
      return *this;
   }
   mint& operator*=(const mint a) {
      (this->x *= a.x) %= MOD;
      return *this;
   }
   mint operator+(const mint a) const {
      mint res(*this);
      return res += a;
   }
   mint operator-(const mint a) const {
      mint res(*this);
      return res -= a;
   }
   mint operator*(const mint a) const {
      mint res(*this);
      return res *= a;
   }
   mint pow(ll t) const {
      if (!t) return 1;
      mint a = pow(t >> 1);
      a *= a;
      if (t & 1) a *= *this;
      return a;
   }
   mint inv() const { return pow(MOD - 2); }
   mint& operator/=(const mint a) { return *this *= a.inv(); }
   mint operator/(const mint a) const {
      mint res(*this);
      return res /= a;
   }
};
istream& operator>>(istream& is, mint& a) {
   return is >> a.x;
}
ostream& operator<<(ostream& os, const mint& a) {
   return os << a.x;
}
struct combination {
   vector<mint> fact, ifact;
   combination(int n) : fact(n + 1), ifact(n + 1) {
      assert(n < MOD);
      fact[0] = 1;
      for (int i = 1; i <= n; ++i)
         fact[i] = fact[i - 1] * i;
      ifact[n] = fact[n].inv();
      for (int i = n; i >= 1; --i)
         ifact[i - 1] = ifact[i] * i;
   }
   mint operator()(int n, int k) {
      if (k < 0 || k > n) return 0;
      return fact[n] * ifact[k] * ifact[n - k];
   }
   mint p(int n, int k) { return fact[n] * ifact[n - k]; }
} comb(200005);

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, m, k;
   cin >> n >> m >> k;
   mint ans = 0;
   rep(dx, 0, m) {
      mint res = mint(dx) * mint(m - dx);
      res = res * mint(n) * mint(n);
      ans += res;
   }
   rep(dy, 0, n) {
      mint res = mint(dy) * mint(n - dy);
      res = res * mint(m) * mint(m);
      ans += res;
   }
   ans *= comb(n * m - 2, k - 2);
   cout << ans << endl;
   return 0;
}