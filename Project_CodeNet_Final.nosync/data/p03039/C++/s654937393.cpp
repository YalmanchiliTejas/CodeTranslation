#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int MOD = 1000000007;

struct mint {
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return a.n == 0 || b.n == 0 ? 0 : (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }
ostream &operator<<(ostream &o, mint a) { return o << a.n; }

mint modinv(mint n) {
  int a = n.n;
  int b = MOD;
  int s = 1;
  int t = 0;
  while (b != 0) {
    int q = a / b;
    a -= q * b;
    s -= q * t;
    swap(a, b);
    swap(s, t);
  }
  if (s < 0) s += MOD;
  return s;
}
mint operator/(mint a, mint b) { return a * modinv(b); }

mint f(mint n) {
  return n * (n + 1) / 2;
}

vector<mint> F_{1, 1}, R_{1, 1}, I_{0, 1};

void check_fact(int n) {
  for (int i = I_.size(); i <= n; i++) {
    I_.push_back(I_[MOD % i] * (MOD - MOD / i));
    F_.push_back(F_[i - 1] * i);
    R_.push_back(R_[i - 1] * I_[i]);
  }
}

mint I(int n) { check_fact(n); return I_[n]; }
mint F(int n) { check_fact(n); return n < 0 ? 0 : F_[n]; }
mint R(int n) { check_fact(n); return n < 0 ? 0 : R_[n]; }
mint C(int n, int r) { return F(n) * R(n - r) * R(r); }
mint P(int n, int r) { return F(n) * R(n - r); }
mint H(int n, int r) { return n == 0 ? (r == 0) : C(n + r - 1, r); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long H, W, K;
  cin >> H >> W >> K;
  mint p = 0;
  mint q = 0;
  for (int i = 0; i < H; i++) {
    p += f(i) * W * W;
  }
  for (int i = 0; i < W; i++) {
    q += f(i) * H * H;
  }
  mint ans;
  ans += C(H*W-2,K-2)*p;
  ans += C(H*W-2,K-2)*q;
  cout << ans.n << '\n';
}
