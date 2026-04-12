#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
typedef long long unsigned int ll;
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)

#define rep(i,n) for(auto i=0; i<(n); i++)
#define isValidPoint(x, y, mx, my) x >= 0 && x  < mx && y >= 0 && y < my

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;

struct Pony
{
    long a, b;
 
    Pony(long a_, long b_)
    {
        a = a_;
        b = b_;
    }
 
    bool operator<(const Pony &another) const
    {
        return b < another.b;
    };
};

int fac(int k){
    int sum = 0;
    for (int i = 1; i <= k; ++i)
    {
        sum += i;
    }
    return sum;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;

  cin >> n;

  vector<long> a(n);

  fillLong(a, n);

  vector<long> c;
  int sz = 0;
  for(int i = n-1; i>=0; i--) {
      int u = ubv(c, a[i]);
      if (u == sz) {
        c.push_back(a[i]);
        sz++;
      } else {
        c[u] = a[i];
      }
  }

  cout << c.size() << endl;
}
