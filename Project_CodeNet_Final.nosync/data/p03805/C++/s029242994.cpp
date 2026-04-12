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

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;

bool G[8][8];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    G[a][b] = true;
    G[b][a] = true;
  }

  vector<int> v(n-1);
  rep(i, n-1) {
    v[i] = i+1;
  }

  int cnt = 0;
  do {
    bool can = true;
    if(!G[0][v[0]]) can = false;
    rep(i, n-2) {
      if(!G[v[i]][v[i+1]]) can = false;
    }
    if (can) cnt++;
  } while(next_permutation(v.begin(), v.end()));

  cout << cnt << endl;
}
