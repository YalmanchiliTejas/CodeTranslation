#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
template <typename T>
ostream& operator<<(ostream& os, vector<T>& a) {
  for (int i = 0; i < (int)a.size(); ++i)
    os << a[i] << " \n"[i == (int)a.size() - 1];
  return os;
}

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int x;
  cin >> x;
  if (x >= 30)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
