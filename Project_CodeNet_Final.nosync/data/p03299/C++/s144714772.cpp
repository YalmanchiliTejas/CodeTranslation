#ifndef LOCAL
#pragma GCC optimize ("O3")
#endif

#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(x...) " [" #x ": " << (x) << "] "

using ld = long double;
using ll = long long;

constexpr int mod = 1000 * 1000 * 1000 + 7;
constexpr int odw2 = (mod + 1) / 2;

void OdejmijOd(int& a, int b) { a -= b; if (a < 0) a += mod; }
int Odejmij(int a, int b) { OdejmijOd(a, b); return a; }
void DodajDo(int& a, int b) { a += b; if (a >= mod) a -= mod; }
int Dodaj(int a, int b) { DodajDo(a, b); return a; }
int Mnoz(int a, int b) { return (ll) a * b % mod; }
void MnozDo(int& a, int b) { a = Mnoz(a, b); }
int Pot(int a, int b) { int res = 1; while (b) { if (b % 2 == 1) MnozDo(res, a); a = Mnoz(a, a); b /= 2; } return res; }
int Odw(int a) { return Pot(a, mod - 2); }
void PodzielDo(int& a, int b) { MnozDo(a, Odw(b)); }
int Podziel(int a, int b) { return Mnoz(a, Odw(b)); }
int Moduluj(ll x) { x %= mod; if (x < 0) x += mod; return x; }

template <typename T> T Maxi(T& a, T b) { return a = max(a, b); }
template <typename T> T Mini(T& a, T b) { return a = min(a, b); }

constexpr int nax = 105;

vector<int> hs;

int n, m;
int pot2[nax];
int h[nax];
int myj[nax];
int dp[nax][nax];

int Popsuj(int hx) {
  return Odejmij(Pot(2, hx), 1);
}

int Algos() {
  debug() << imie(hs) imie(n) imie(m) imie(range(h + 1, h + n + 1));
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (h[i] == hs[j]) {
        myj[i] = j;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    if (hs[j] < h[1]) {
      dp[1][j] = Mnoz(Mnoz(2, Pot(2, max(0, h[1] - hs[j + 1]))), Popsuj(hs[j + 1] - hs[j]));
    } else if (hs[j] == h[1]) {
      dp[1][j] = 2;
    } else {
      dp[1][j] = 0;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      const int val = dp[i - 1][j];
      if (!val) continue;
      debug() << "dp[" << i - 1 << "][" << j << "] = " << val;

      if (h[i] <= hs[j]) {
        DodajDo(dp[i][myj[i]], Mnoz(val, 2));
      } else if (h[i] <= h[i - 1]) {
        DodajDo(dp[i][j], val);
      } else if (hs[j] < h[i - 1]) {
        DodajDo(dp[i][j], Mnoz(val, Pot(2, h[i] - h[i - 1])));
      } else {
        for (int j2 = j; j2 <= m and hs[j2] <= h[i]; j2++) {
          debug() << imie(j2);
          if (hs[j2] < h[i]) {
            //debug() << imie(Mnoz(Mnoz(2, val), Odejmij(Pot(2, h[i] - hs[j2]), 1)));
            //DodajDo(dp[i][j2], Mnoz(Mnoz(2, val), Odejmij(Pot(2, h[i] - hs[j2]), 1)));
            DodajDo(dp[i][j2], Mnoz(Mnoz(Mnoz(2, val), Pot(2, max(0, h[i] - hs[j2 + 1]))), Popsuj(hs[j2 + 1] - hs[j2])));
          } else {
            //debug() << imie(Mnoz(val, 2));
            DodajDo(dp[i][j2], Mnoz(val, 2));
          }
        }
      }
    }
  }
  int wyn = 0;
  for (int j = 1; j <= m; j++) {
    const int val = dp[n][j];
    if (!val) continue;
    debug() << "hdp[" << n << "][" << j << "] = " << val;
    DodajDo(wyn, val);
  }
  return wyn;
}

int main() {
  pot2[0] = 1;
  for (int i = 1; i < nax; i++) pot2[i] = Mnoz(pot2[i - 1], 2);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    hs.push_back(h[i]);
  }
  hs.push_back(0);
  hs.push_back(1);
  sort(hs.begin(), hs.end());
  hs.resize(unique(hs.begin(), hs.end()) - hs.begin());
  m = (int) hs.size() - 1;
  cout << Algos() << endl;
  return 0;
}
