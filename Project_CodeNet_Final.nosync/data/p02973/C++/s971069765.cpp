/*
g++ --std=c++17 A.cpp
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

const int INF = 1e9;
const int MOD = 1000000007;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  int ans = 0;
  multiset<int> ms;
  rep(i, n) {
    int x;
    cin >> x;
    multiset<int>::iterator it;
    //! EMPTY      <-- 2 => 2               //! when empty, insert x
    //! 2, 2, 4, 4 <-- 1 => 1, 2, 2, 4, 4   //! when lb(x) == begin(), insert x
    //! 2, 2, 4, 4 <-- 2 => 2, 2, 2, 4, 4   //! when lb(x) == begin(), insert x
    //! 2, 2, 4, 4 <-- 3 => 2, 3, 4, 4      //! when lb(x) != begin(), replace the prev number with x
    //! 2, 2, 4, 4 <-- 4 => 2, 4, 4, 4      //! when lb(x) != begin(), replace the prev number with x
    //! 2, 2, 4, 4 <-- 5 => 2, 2, 4, 5      //! when lb(x) != begin(), replace the prev number with x
    if (ms.empty() || (it = ms.lower_bound(x)) == ms.begin()) {
      ++ans;
      ms.insert(x);
    } else {
      --it;
      ms.erase(it);
      ms.insert(x);
    }
  }

  cout << ans << endl;

  return 0;
}
