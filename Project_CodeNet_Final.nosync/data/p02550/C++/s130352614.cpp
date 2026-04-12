/*
g++ --std=c++17 E.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
template<class T> inline bool chmax(T& a, T b) { bool ret = (a < b); if (ret) { a = b; } return ret; }
template<class T> inline bool chmin(T& a, T b) { bool ret = (b < a); if (ret) { a = b; } return ret; }
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int INF = 1000000000;
const int MOD = 1000000007;

LL n;
int x, m;
LL a[100000];
LL sum[100000];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> x >> m;
  map<int, int> occ; //! number => first occurance

  int begin = 0;
  int end = 0;
  a[1] = x;
  sum[0] = 0;
  sum[1] = x;
  occ[x] = 1;
  for (int i = 2; begin == 0 && i < m+10; ++i) {
    a[i] = (a[i-1] * a[i-1]) % m;
    sum[i] = sum[i-1] + a[i];
    if (occ[a[i]]) {
      begin = occ[a[i]];
      end = i;
    } else {
      occ[a[i]] = i;
    }
  }

  LL ans = sum[begin-1];
  int len = end - begin;
  LL repCount = (n-begin+1) / len;
  ans += repCount * (sum[end-1] - sum[begin-1]);
  int restCount = (n-begin+1) % len;
  ans += sum[begin+restCount-1] - sum[begin-1];
  
  cout << ans << endl;

  return 0;
}
