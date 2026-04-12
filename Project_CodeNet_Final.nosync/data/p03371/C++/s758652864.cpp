#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

#define MOD 1000000007
#define INF 1e9+7
#define INF_LONG 1e18
#define rep(i, n) for(int i=0; i<n; ++i)
#define rrep(i, m, n) for(int i=m; i<n; ++i)
typedef long long ll;

#define MAX_N 200000
#define MAX_M 100000
#define MAX_V 100
#define MAX_E 100
#define MAX_Q 100000

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int ddx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int ddy[] = {0, -1, 0, 1, 1, 1, -1, -1};

ll gcd(ll x, ll y) {
  if(y==0) return x;
  else return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
  return (x*y)/gcd(x, y);
}

//--------------------------

int main() {

  int a, b, c; cin >> a >> b >> c;
  int x, y; cin >> x >> y;
  ll cost = 0;

  int m = min(x, y);
  int mx = 0, my = 0;
  if(x-m!=0) mx = x-m;
  else my = y-m;

  if(a+b>2*c) {
    cost += 2*c*m;
  }else {
    cost += a*m + b*m;
  }

  if(mx!=0) {
    if(a>2*c) cost += 2*c*mx;
    else cost += a*mx;
  }else {
    if(b>2*c) cost += 2*c*my;
    else cost += b*my;
  }

  cout << cost << endl;

  return 0;
}
