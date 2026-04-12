
#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;

ll layers[55];
ll ps[55];

ll solve(int n, ll x) {
  if(x == layers[n]) {
    return ps[n];
  } else if(x == 1) {
    return 0;
  } else if(x <= 1 + layers[n-1]) {
    return solve(n-1, x-1);
  } else if(x == 1 + layers[n-1] + 1) {
    return ps[n-1] + 1;
  } else if(x <= 1 + layers[n-1] + 1 + layers[n-1]) {
    return ps[n-1] + 1 + solve(n-1, x-(1 + layers[n-1] + 1));
  } else {
    assert(false);
  }
}


int main(void) {
  int n;
  ll x;
  cin >> n >> x;
  layers[0] = 1;
  ps[0] = 1;
  REP(i, n) {
    ps[i+1] = ps[i]*2 + 1;
    layers[i+1] = layers[i]*2 + 3;
  }
  ll res = solve(n, x);
  cout << res << endl;
  return 0;
}
