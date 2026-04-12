#define STOPIT
#include <bits/stdc++.h>
#define loop(n) for (lint ngtkana_is_a_genius = 0; ngtkana_is_a_genius < lint(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (lint i = lint(begin); (i) < lint(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto&& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto&& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) {}
#endif

/*
a = b * q + r と表して、(b,q,r) の個数を求めます。
b を固定して数えます。
まず 余りがなんでも大丈夫な q は q in [0,Q[ where Q = floor((n+1) / b) です。
q = Q のときは Θ(b) 書けて全探索です。
  - これは嘘で、間に合わないので R = n - Q*b として、[k,R] です。
k = 0 のとき、(0,b) がなみ入るので n 引いておきましょう。
*/

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  lint n, k; std::cin >> n >> k;
  lint ans = 0;
  rep(b,k+1,n+1) {
    lint Q = (n+1) / b;
    lint rs = b - k;
    lint now = Q * rs;
    lint R = n - Q * b;
    lint add = R - k + 1;
    if (0 <= add) {
      now += add;
    }
    ans += now;
  }
  if (k==0) {
    ans -= n;
  }
  std::cout << ans << std::endl;
  return 0;
}