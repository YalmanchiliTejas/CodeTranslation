#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

vector<ll> l(51),p(51);
ll res = 0;

ll f(ll n,ll x) {
  if (n == 0) {
    return (x == 1) ? 1 : 0;
  }
  if (x == 1) return 0;
  else if (x < l[n-1] + 2) {
    return f(n-1, x-1);
  } else if (x == l[n-1] + 2) {
    return p[n-1] + 1;
  } else if (x < l[n]) {
    return p[n-1] + 1 + f(n-1, x - l[n-1] - 2);
  } else {
    return p[n];
  }
}

int main() {
  ll n,x; cin >> n >> x;
  l[0] = p[0] = 1;
  rep_r(i,n+1,1) {
    l[i] = l[i-1] * 2 + 3;
    p[i] = p[i-1] * 2 + 1;
  }

  cout << f(n,x) << endl;
}
