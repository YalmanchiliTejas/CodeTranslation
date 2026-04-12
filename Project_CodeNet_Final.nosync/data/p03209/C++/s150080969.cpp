#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int N;
ll X;
ll l[60];

ll query(int n, ll x) {
  if (n == 0) {
    if (x == 1) {
      return 1LL;
    } else {
      return 0LL;
    }
  } else if (n == 1) {
    if (x >= 4) {
      return 3LL;
    } else if (x == 3) {
      return 2LL;
    } else if (x == 2) {
      return 1LL;
    } else {
      return 0LL;
    }
  } else {
    if (x >= l[n]-1) {
      ll tmp = query(n-1, l[n-1]);
      return tmp * 2 + 1;
    } else if (x >= (l[n-1] + 2)) {
      ll d = x - (l[n-1] + 2);
      ll tmp1 = query(n-1, l[n-1]);
      ll tmp2 = query(n-1, d);
      return tmp1 + tmp2 + 1;
    } else if (x >= (l[n-1] + 1)) {
      ll tmp = query(n-1, l[n-1]);
      return tmp;
    } else if (x >= 1) {
      ll tmp2 = query(n-1, x-1);
      return tmp2;
    } else {
      return 0LL;
    }
  }
}

int main () {
  cin >> N >> X;

  l[0] = 1;
  rep(i, 50) {
    l[i] = l[i-1] * 2 + 3;
  }

  cout << query(N, X) << "\n";
}