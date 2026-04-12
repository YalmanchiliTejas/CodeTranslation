/*
 * atcoder/abc134/e.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
#include <set>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> ostream & operator << (ostream & out, vector<T> const & v) {
  for (auto &&a: v) out << a << " "; out << endl; return out;
}
template <class T> void dump(T &a) { cout << a << endl; }
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

/*
 * Aの要素をK個の色で塗り分けることはK個のグループに分けるとみなせる.
 * そのグループの条件は狭義単調増加列であること.
 * 既存のグループを管理しながら、条件を満たしつつ既存のグループに追加していき、
 * 条件を満たせない場合は新規のグループを作れば良い.
 * 条件を満たすグループが複数ある場合は「もっともきつい」グループを貪欲に選択すれば良い.
 * 「もっともきつい」とは、右端が最も大きいグループのこと.
 * 右端が最大でないものを選んでしまうと後で追加できたはずの要素が追加できなくなり、
 * 損をすることになる.
 */
int N;
vector<int> A;
void solve() {
  cin >> N;
  A.resize(N);

  // S := Aを最初から見ていった時に、既存の単調増加部分列に追加出来る場合は末尾に追加、
  // 出来ない場合は新規の単調増加部分列を作成、としていった時に出来る単調増加部分列群の
  // 右端の値の集合.
  // 右端の情報さえあれば、その単調増加部分列に追加可能か判定できる.
  multiset<int> S;

  loop(n,0,N) cin >> A[n];

  for (auto&&a: A) {
    auto iter = S.lower_bound(a); // a以上の最初の値を見つける
    // 見つかった場合、aより小さい右端をもつ単調増加部分列があるということ.
    // 同じ値が複数ある場合lower_boundは最初の場所を返すので、iter - 1 は必ずa未満
    // そのa未満の右端をもつ単調増加部分列に追加（右端を、消して上書きする）
    if (iter != S.begin()) S.erase(--iter);
    // 上記までで消した場合は上書きになり、消さない場合は新規追加
    S.insert(a);
  }
  cout << S.size() << endl;

}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
