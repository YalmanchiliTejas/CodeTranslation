#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ff first
#define ss second
#define ll long long
#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vss vector<vs>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define repr(i, a, n) for (int i = (n); i >= (a); --i)
using namespace std;
const int INF(1 << 30);
const ll LLINF(1LL << 55LL);
const int pi = 3.1415926536;
const int MOD = 1000000007;
const int MAX = 510000;

void Main() {
  int r, g, b;
  cin >> r >> g >> b;
  cout << (((r * 100 + g * 10 + b) % 4 == 0) ? "YES" : "NO") << endl;
}

int main() {
  std::cin.tie(nullptr);                  // 標準入出力高速化
  std::ios_base::sync_with_stdio(false);  // SとS++の入出力出力を非同期
  std::cout << std::fixed << std::setprecision(15);  // 小数を10進数表示
  Main();
}