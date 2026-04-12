#include <iostream>
#include <algorithm>
#include <ostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;

template <typename T, typename U>
std::ostream& operator << (std::ostream& out, std::pair<T, U> p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T> v) {
  out << "[";
  for (int i = 0; i < v.size(); ++i) {
    out << v[i] << (i == (v.size() - 1) ? "" : ", ");
  }
  out << "]";
  return out;
}

int N;
ll X;
ll burger[51] = { 0 }; // burger[i] := レベル N に含まれるパティの数
ll layer_num = 1;

// バーガーの下(b)と上(t)とレベル(level)
// 閉区間 [b, t]
ll solve(ll b, ll t, ll level) {
  //cerr << "b, t, level = " << b << ", " << t << ", " << level << endl;
  //cerr << endl;
  if (b > X) {
    //cerr << "b >= X" << endl;
    return 0;
  }

  if (level == 0) {
    //cerr << "level 0" << endl;
    return 1;
  }
  if (t <= X) {
    //cerr << "t <= X" << endl;
    return burger[level];
  }
  //cerr << "next : (" << b + 1 << ", " << (t + b) / 2 - 1 << "), ... (" << (t + b) / 2 + 1 << ", " << t - 1 << ")" << endl;
  return solve(b + 1, (t + b) / 2 - 1, level - 1) + solve((t + b) / 2 + 1, t - 1, level - 1) + (X >= (t + b) / 2);
}

int main() {
  cin >> N >> X;
  X--;
  //cerr << "X's index : " << X << endl;

  burger[0] = 1;

  // レベル i に含まれるパティの数を求める
  for (int i = 1; i <= N; ++i) {
    burger[i] = burger[i - 1] * 2 + 1;
  }

  // レベル N のバーガーの総層数を求める
  layer_num = 1;
  for (int i = 1; i <= N; ++i) {
    layer_num = layer_num * 2 + 3;
  }
  cout << solve(0, layer_num - 1, N) << endl;

  return 0;
}