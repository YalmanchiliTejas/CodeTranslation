#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

int n, m;
vvi g;
int main() {
  scanf("%d %d", &n, &m);
  g.assign(n, vi(n, 0));
  rep (i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1; b -= 1;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  vi data(n);
  rep (i, n) {
    data[i] = i;
  }
  int ans = 0;
  int cnt = 0;
  do {
    assert (data[0] == 0);
    cnt += 1;
    bool flag = true;
    rep (i, n-1) {
      if (g[data[i]][data[i+1]] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      ans += 1;
    }
  } while (next_permutation(begin(data) + 1, end(data)));
  printf("%d\n", ans);

  return 0;
}
