#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int n;
  cin >> n;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < i; ++j) {
      if (i == j) continue;
      if (h[i] < h[j]) {
        flag = false;
        break;
      }
    }
    if (flag) ans += 1;
  }

  cout << ans << endl;
}
