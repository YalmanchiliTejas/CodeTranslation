#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  lint n, x, m; cin >> n >> x >> m;

  if (n <= 1000000) {

    vector<lint> t(m, -1);
    vector<lint> a(n, -1);

    lint cur = x;
    lint sum = 0;
    for (int i = 0; i < n; i++) {
      sum += cur;
      a[i] = cur;
      t[cur] = i;
      cur = cur * cur % m;
    }

    cout << sum << endl;
    return 0;
  }

  vector<lint> t(m, -1);

  lint cur = x;
  lint T = -1;
  lint val = -1;
  for (int i = 0; i < n; i++) {
    t[cur] = i;
    lint pre = cur;
    cur = cur * cur % m;

    if (t[cur] != -1) {
      T = t[pre] - t[cur] + 1;
      val = cur;
      break;
    }
  }

  lint cost = 0; // 一週分のコスト
  cur = val;
  while (1) {
    cost += cur;
    cur = cur * cur % m;
    if (cur == val) break;
  }

  // val に当たるまでは、普通に計算。
  lint ans = 0;
  cur = x;
  while (1) {
    ans += cur;
    n--;
    cur = cur * cur % m;
    if (cur == val) break;
  }

  // 残り n 個
  ans += (n / T) * cost;
  n = n % T;
  
  for (int i = 0; i < n; i++) {
    ans += cur;
    cur = cur * cur % m;
  }

  cout << ans << endl;



  return 0;
}
