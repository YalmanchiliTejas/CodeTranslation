#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define range(a) a.begin(), a.end()

constexpr int MOD = 998244353;

class mint {
  int n;
public:
  mint(int n_ = 0) : n(n_) {}
  explicit operator int() { return n; }
  friend mint operator-(mint a) { return -a.n + MOD * (a.n != 0); }
  friend mint operator+(mint a, mint b) { int x = a.n + b.n; return x - (x >= MOD) * MOD; }
  friend mint operator-(mint a, mint b) { int x = a.n - b.n; return x + (x < 0) * MOD; }
  friend mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
  friend mint &operator+=(mint &a, mint b) { return a = a + b; }
  friend mint &operator-=(mint &a, mint b) { return a = a - b; }
  friend mint &operator*=(mint &a, mint b) { return a = a * b; }
  friend bool operator==(mint a, mint b) { return a.n == b.n; }
  friend bool operator!=(mint a, mint b) { return a.n != b.n; }
  friend istream &operator>>(istream &i, mint &a) { return i >> a.n; }
  friend ostream &operator<<(ostream &o, mint a) { return o << a.n; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, S; cin >> N >> S;
  vector<int> A(N); rep(i, N) cin >> A[i];
  vector<mint> f(S + 1);
  mint ans;
  rep(i, N) {
    f[0] += 1;
    for (int j = S - A[i]; j >= 0; j--) {
      f[j + A[i]] += f[j];
    }
    ans += f[S];
  }
  cout << ans << endl;
}