#include "bits/stdc++.h"
#ifndef err
#define err(...)(void)0
#endif
using namespace std;
using ll = long long;
using ull = decltype(1ull);
template<class T>int size(T&&a) { return a.size(); }
#define REP(t,a)for(typename make_signed<decltype(a.second)>::type t=a.first,_l##t=a.second;t<_l##t;t++)
#define RREP(t,a)for(typename make_signed<decltype(a.second)>::type t=a.second-1,_l##t=a.first;t>=_l##t;t--)
template<class B>pair<int, B>make_pair(B b) { return{ 0,b }; }
#define rep(t,...)REP(t,make_pair(__VA_ARGS__))
#define rrep(t,...)RREP(t,make_pair(__VA_ARGS__))
#define all(a)begin(a),end(a)
#define rall(a)a.rbegin(),a.rend()

void Calc();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cin.exceptions(istream::failbit | istream::badbit);
  cout << fixed << setprecision(15); Calc(); cout.flush(); return 0;
}
template<class A>void amax(A&a, A b) { a = max(a, b); }
template<class A>void amin(A&a, A b) { a = min(a, b); }
struct Scanner {
  template<class A = string>A Next() { A a; cin >> a; return a; }
  template<class A = int>vector<A>Array(int n) { vector<A>a(n); for (A&i : a) cin >> i; return a; }
  string Line() const { string s; getline(cin, s); return s; }
  template<class A>Scanner&operator,(A&a) { a = Next<A>(); return *this; }
  template<class A>operator A() { return Next<A>(); }
}in;

/*---------------------------------------------------------------------*/

template<class T, class B, class...V>struct Vec {
  typedef Vec<T, V...>A; typedef vector<typename A::t>t; t nvec(B a, V...b) { return t(a, A().nvec(b...)); }
};
template<class T, class B>struct Vec<T, B> { typedef vector<T>t; t nvec(B a) { return t(a); } };
template<class T>tuple<T>Init(T t) { return tuple<T>(t); }
template<class T, class C>struct Vec<T, tuple<C>> { using t = T; T nvec(tuple<C> a) { return get<0>(a); } };
template<class T = int, class...B> typename Vec<T, B...>::t nvec(B...b) { return Vec<T, B...>().nvec(b...); }


vector<vector<int>> v;

void Calc() {


  int n, m;
  in, n, m;

  v = nvec((int) pow(2, n), 0);
  rep(i, m) {
    int a, b;
    in, a, b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (auto& i : v) {
    sort(all(i));
  }
  auto dp = nvec(n+1, 1 << n);
  dp[1][1] = 1;
  rep(i, 1, 1 << n) {
    rep(j, n) rep(k, n) {
      if ((i & (1 << k)) == 0) {
        if (std::find(all(v[j]), k) != v[j].end()) {
          dp[k+1][i | (1 << k)] += dp[j+1][i];
        }
      }
    }
  }
  err(dp);

  int cnt = 0;
  for (auto& i : dp) {
    cnt += i[(1 << n) - 1];
  }
  cout <<  cnt<< endl;

}
