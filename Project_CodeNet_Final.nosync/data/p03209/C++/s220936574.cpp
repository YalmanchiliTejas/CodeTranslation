#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define REP(i,s,e) for(int i=(s);i<(e);i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef unsigned long long ull;

vector<ll> a, p;

ll f(ll n, ll x) {
  if (n == 0)
    return x <= 0 ? 0 : 1;
  else if (x <= 1 + a[n - 1])
    return f(n - 1, x - 1);
  else
    return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}

int main(void) {
  ll N, X; cin >> N >> X;

  a.push_back(1);
  p.push_back(1);

  rep(i, N) {
    a.push_back(a[i] * 2 + 3);
    p.push_back(p[i] * 2 + 1);
  }

  cout << f(N, X) << endl;
  return 0;
}
