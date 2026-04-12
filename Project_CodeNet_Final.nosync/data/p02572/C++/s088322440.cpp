#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>
#include <bitset>
#define rep(i,r) for(int i = 0; i < (r); i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define uint unsigned long long
#define endl '\n'
using namespace std;

template <typename T> struct Modular {
  /* to abbreviate the word "Modular" */
  using M = Modular; 

  /* Infers type from template. The struct/class T must have 
     "modulus" defined as member.*/
  using Type = typename decay<decltype(T::value)>::type; 

  /* Mod() is now an alias to the "modulus" (eg 1e9+7) */
  constexpr static Type Mod() { return  T::value; }

  /* v is the value of the Mint. [0 <= v < Mod) */
  Type v;
  Modular(long long a = 0) : v((a %= Mod()) < 0 ? a + Mod() : a) {}
  M operator-() const { return M() -= *this; }
  M& operator+=(M r) { if ((v += r.v) >= Mod()) v -= Mod(); return *this; }
  M& operator-=(M r) { if ((v += Mod() - r.v) >= Mod()) v -= Mod(); return *this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % Mod(); return *this; }
  M& operator/=(M r) { return *this *= mdpow(r, Mod() - 2); }
  M& operator++() { return *this += M(1); };
  M& operator--() { return *this -= M(1); };
  friend M operator+(M l, M r) { return l += r; }
  friend M operator-(M l, M r) { return l -= r; }
  friend M operator*(M l, M r) { return l *= r; }
  friend M operator/(M l, M r) { return l /= r; }
  friend bool operator==(M l, M r) { return l.v == r.v; }
  friend M mdpow(M b, unsigned exp) {
    Modular res(1);
    while(exp) {
      if (exp & 1) {
        res *= b;
        if ((res.v += Mod()) >= Mod()) res.v -= Mod();
      }
      b *= b;
      exp >>= 1;
    }
    return res;
  }
};

constexpr unsigned md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

signed main() {
    fastio;
    int n; 
    cin >> n;
    vector<Mint> a;
    rep (i, n) {
        int ai;
        cin >> ai;
        a.pb(Mint(ai));
    }

    vector<Mint> pre(n+1, Mint(0));
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    Mint res(0);
    rep(i, n) {
        Mint sub = pre[n] - pre[i + 1];
        res += sub * a[i];
    }
    cout << res.v << endl;
    
}