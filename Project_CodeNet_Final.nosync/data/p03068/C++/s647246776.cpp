#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
#define INF 1e10
using namespace std;
template<typename T> void cmin(T &a, T b) { a = min(a, b); }
template<typename T> void cmax(T &a, T b) { a = max(a, b); }

signed main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  char tar = s[k - 1];
  rep(i, s.size()) {
    if (s[i] != tar) {
      cout << '*';
    } else {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}
