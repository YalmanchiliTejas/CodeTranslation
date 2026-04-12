#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#define typeof(x) __typeof__(x)
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);--i)

#define ALL(c) (c).begin(),(c).end()
#define SZ(c) (int)((c).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define SORT(c) sort(ALL(c))
#define LB(c,x) (int)(lower_bound(ALL(c),x)-(c).begin())
#define UB(c,x) (int)(upper_bound(ALL(c),x)-(c).begin())
#define COUNT(c,x) UB(c,x)-LB(c,x)
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define PB push_back
#define MP make_pair
#define vec vector

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using namespace std;

struct edge {
  int to, cost;
};

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator << (ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
  for (int i = 0; i < len; i++) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  s << "]";
  return s;
}


signed main()
{
  int n; cin >> n;
  vec<int> a(n);
  rep(i, 0, n) {
    cin >> a[i];
  }

  deque<int> dq;
  rep(i, 0, n) {
    if ((n-i) % 2 == 1) {
      dq.push_front(a[i]);
    } else {
      dq.push_back(a[i]);
    }
  }

  rep(i, 0, n) {
    cout << dq[i] << " ";
  }
  cout << endl;
  return 0;
}
