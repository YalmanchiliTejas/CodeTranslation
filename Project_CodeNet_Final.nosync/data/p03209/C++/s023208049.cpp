#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>
#include <bitset>
#include <stack>

using namespace std;
typedef long long ll;

ll all[51], pat[51];

ll search(ll N, ll X) {
  if (all[N] == X) {
    return pat[N];
  }
  
  ll ans = 0;
  // 一枚目
  X--;

  // 下
  if (X > 0) {
    ll l = min(X, all[N - 1]);
    ans += search(N - 1, l);
    X -= l;
  }
  
  // 中
  if (X > 0) {
    X--;
    ans++;
  }
  
  // 上
  if (X > 0) {
    ll l = min(X, all[N - 1]);
    ans += search(N - 1, l);
    X -= l;
  }
  
  return ans;
}

int main() {
  ll N, X;
  cin >> N >> X;
  
  all[0] = 1;
  pat[0] = 1;
  for (int i = 1; i < 50; i++) {
    all[i] = all[i - 1] * 2 + 3;
    pat[i] = pat[i - 1] * 2 + 1;
  }
  
  cout << search(N, X) << endl;
  return 0;
}
