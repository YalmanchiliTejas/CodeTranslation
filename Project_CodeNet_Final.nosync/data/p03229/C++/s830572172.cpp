#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>

typedef long double ld;
typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

// Split
namespace util {

std::vector< std::string > split(std::string s, char delimiter)
{
  std::vector< std::string > vs;
  std::string sub;
  for (auto c : s) {
    if (c == delimiter) vs.push_back(sub), sub.clear();
    else sub += c;
  }
  vs.push_back(sub);
  return vs;
}

} // namespace util

// Minimum, Maximum
template<class T> T minimum(T head, T tail) { return std::min(head, tail); }
template<class H, class... T> H minimum(H head, T... tail) { return std::min(head, minimum(tail...)); }
template<class T> T maximum(T head, T tail) { return std::max(head, tail); }
template<class H, class... T> H maximum(H head, T... tail) { return std::max(head, maximum(tail...)); }

// Output
template<class T, class S> std::ostream& operator << (std::ostream& os, std::pair<T, S> p)
{
  return os << "(" << p.first << " " << p.second << ")";
}

template<class T> std::ostream& operator << (std::ostream& os, std::vector< T > v)
{
  for (ll i = 0; i < (ll)v.size(); i++){ os << " [" << i << "]" << v[i]; if (i % 10 == 9) os << std::endl; }
  //os << v[0]; for (ll i = 1; i < (ll)v.size(); i++){ os << " " << v[i]; }
  return os;
}

template<class T, class S> std::ostream& operator << (std::ostream& os, std::map< T, S > m)
{
  ll i = 0; for (auto p : m){ os << " [" << i << "]" << p.first << "->" << p.second; i++;}
  return os;
}

void print(){ std::cout << std::endl; }
template<typename H> void print(H head) { std::cout << head << std::endl; }
template<typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector< ll > va(N, 0LL);
  for (ll i = 0; i < N; i++) {
    std::cin >> va[i];
  }

  // ■ 奇数個のデータの場合
  //    並べ替えた列を a1, a2, ..., a5 とする
  //    奇数番号の数値が偶数番号の数値より大きい場合
  //    a1 >= a2 <= a3 >= a4 <= a5 なので
  //    result = (a1 - a2) + (a3 - a2) + (a3 - a4) + (a5 - a4)
  //           = + a1 - 2a2 + 2a3 - 2a4 +  a5
  //           = -2a2 - 2a4 +  a1 +  a5 + 2a3
  //
  //    偶数番号の数値が奇数番号の数値より大きい場合は
  //    a1 <= a2 >= a3 <= a4 >= a5 なので
  //    result = (a2 - a1) + (a2 - a3) + (a4 - a3) + (a4 - a5)
  //           = - a1 + 2a2 - 2a3 + 2a4 -  a5
  //           = -2a3 -  a1 -  a5 + 2a2 + 2a4
  //
  //    となるので, それぞれのパターンでソートした情報を当てはめていく
  //    ※ - 2a3 の場合は, -2 倍した値が result の結果に乗るので, 一番小さな値を入れるべき
  //
  // ■ 偶数個のデータの場合
  //    奇数番号の数値が偶数番号の数値より大きい場合も, その逆も同じ結果になりそうだが, ２パターン考える
  //    a1 >= a2 <= a3 >= a4 のケースのみを考えると
  //    result = (a1 - a2) + (a3 - a2) + (a3 - a4)
  //           = + a1 - 2a2 + 2a3 - a4
  //
  //    偶数番号の数値が奇数番号の数値より大きい場合は
  //    a1 <= a2 >= a3 <= a4 >= a5 なので
  //    result = (a2 - a1) + (a2 - a3) + (a4 - a3)
  //           = - a1 + 2a2 - 2a3 + a4

  // 上記の方針に従って実装
  // まずソートする
  std::sort(va.begin(), va.end());

  // 係数の配列を 2pattern 作る
  std::vector<ll> vk1(N, 0LL);
  std::vector<ll> vk2(N, 0LL);

  if (N % 2 == 1) {
    // 奇数番号の数値が偶数番号の数値より大きいケース (0 origin なので処理場は逆)
    for (ll i = 0; i < N; i++) {
      vk1[i] = i % 2 == 0 ? 2 : -2;
      vk1[0]   = 1;
      vk1[N-1] = 1;
    }
    // 偶数番号の数値が奇数番号の数値より大きいケース (0 origin なので処理場は逆)
    for (ll i = 0; i < N; i++) {
      vk2[i] = i % 2 == 0 ? -2 : +2;
      vk2[0]   = -1;
      vk2[N-1] = -1;
    }

  } else {
    // 奇数番号の数値が偶数番号の数値より大きいケース (0 origin なので処理場は逆)
    for (ll i = 0; i < N; i++) {
      vk1[i] = i % 2 == 0 ? 2 : -2;
      vk1[0]   = +1;
      vk1[N-1] = -1;
    }
    // 偶数番号の数値が奇数番号の数値より大きいケース (0 origin なので処理場は逆)
    for (ll i = 0; i < N; i++) {
      vk2[i] = i % 2 == 0 ? -2 : +2;
      vk2[0]   = -1;
      vk2[N-1] = +1;
    }
  }

  // 配列 a と掛け算するために並び替える
  std::sort(vk1.begin(), vk1.end());
  std::sort(vk2.begin(), vk2.end());

  //
  // result = (a1 - a2) + (a3 - a2) + (a3 - a4) + (a5 - a4) などの計算を行う
  //
  ll result1 = 0LL;
  ll result2 = 0LL;
  for (ll i = 0; i < N; i++) {
    result1 += vk1[i] * va[i];
    result2 += vk2[i] * va[i];
  }

  // それぞれのケースを比較して, 値が大きい方を答えとする
  ll ans = std::max(result1, result2);
  print(ans);

  return 0;
}
