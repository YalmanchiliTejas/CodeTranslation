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
using P = pair<long, long>;

typedef long long int ll;

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
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;

int counts[200005];

long sizes[55];
long meats[55];

long eat(long n, long x) {
  if (x <= 0) {
    return 0;
  }
  if (x >= sizes[n]) {
    return meats[n];
  }
  if (n == 0) {
    return 1;
  }
  x--;
  long e1 = eat(n-1, x);
  x -= sizes[n-1];
  if (x >= 1) {
    x--;
    long e2 = eat(n-1, x);
    return e1+e2+1;
  } else {
    return e1;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n, x;
  cin >> n >> x;

  sizes[0] = 1;
  meats[0] = 1;

  rep(i, n) {
    sizes[i+1] = sizes[i]*2+3;
    meats[i+1] = meats[i]*2+1;
  }

  cout << eat(n, x) << endl;
}
