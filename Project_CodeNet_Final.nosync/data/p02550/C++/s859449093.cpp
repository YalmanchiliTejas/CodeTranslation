#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
inline bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
inline bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion


/**
 * ダブリング　簡易版
 **/
template<ull Kmax = INF> struct DoublingE {
  int log;
  vector<int> nxt;
  vector<vector<int>> n_table;
  DoublingE(const vector<int> &_nxt) : nxt(_nxt) {
    int n = nxt.size();
    {
      log = 1;
      ull _n = 1;
      while(_n < Kmax){
        _n <<= 1;
        log++;
      }
    }
    n_table.resize(log);
    n_table[0] = nxt;
    for (int i = 1; i < log; i++) {
      n_table[i].resize(n);
      for (int j = 0; j < n; j++) {
        n_table[i][j] = n_table[i-1][n_table[i-1][j]];
      }
    }
  }
  int get(int idx, ull k) {
    int shift = 0;
    while ((k >> shift) > 0ull) {
      if ((k >> shift) & 1) {
        idx = n_table[shift][idx];
      }
      shift++;
    }
    return idx;
  }
};

/**
 * ダブリング
 * i -> nxt[i]のグラフでK個の頂点を辿る
 *
 * 構築 O(N log K)
 * クエリ O(log K)
 * 1 <= K < 2^64
 * T, op: 半群(結合律)
 **/
template <typename T, T (*op)(T, T), ull Kmax = INF> struct Doubling {
  DoublingE<Kmax> dbl;
  vector<T> data;
  vector<vector<T>> d_table;
  Doubling(const vector<int> &_nxt, const vector<T> &_data)
    : dbl(_nxt), data(_data) {
    assert(data.size() == dbl.nxt.size());
    int n = data.size();
    d_table.resize(dbl.log);
    d_table[0] = data;
    for (int i = 1; i < dbl.log; i++) {
      d_table[i].resize(n);
      for (int j = 0; j < n; j++) {
        d_table[i][j] = op(d_table[i-1][j], d_table[i-1][dbl.n_table[i-1][j]]);
      }
    }
  }
  int get(int idx, ull k) {
    return dbl.get(idx, k);
  }
  T get_data(int idx, ull k) {
    return data[dbl.get(idx, k)];
  }
  T prod(int idx, ull k) {
    assert(k > 0);
    k--;
    T ret = data[idx];
    idx = dbl.nxt[idx];
    int shift = 0;
    while ((k >> shift) > 0ull) {
      if ((k >> shift) & 1) {
        ret = op(ret, d_table[shift][idx]);
        idx = dbl.n_table[shift][idx];
      }
      shift++;
    }
    return ret;
  }
};

ll pls(ll x, ll y){ return x + y; }


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, x, m;
  cin >> n >> x >> m;
  vll rem(m);
  vi remi(m);
  rep(i, m){
    rem[i] = i;
    remi[i] = (i*i)%m;
  }
  Doubling<ll, pls, ull(1e10)> db(remi, rem);
  /*
  dump(db.dbl.nxt);
  dump(db.dbl.n_table);
  dump(db.data);
  dump(db.d_table);
  const ll mm = 10;
  vll ans(mm, 0), ansp(mm, 0);
  rep(i, mm){
    ans[i] = db.get(x, i);
    if(i) ansp[i] = db.prod(x, i);
  }
  dump(ans);
  dump(ansp);
  */
  print(db.prod(x, n));
}
