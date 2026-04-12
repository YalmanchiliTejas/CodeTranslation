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

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

vector<ll> p(51), total(51);

ll rec(ll n, ll x) {
  if (n == 0) return (x == 1) ? 1 : 0;
  
  if (x == 1) return 0;
  else if (x < total[n-1] + 2) {
    return rec(n-1, x-1);
  } else if (x == total[n-1] + 2) {
    return p[n-1] + 1;
  } else if (x < total[n]) {
    return p[n-1] + 1 + rec(n-1, x - total[n-1] - 2);
  } else {
    return p[n];
  }
}

int main() {
  ll n,x;
  cin >> n >> x;
  p[0] = 1, total[0] = 1;

  for (int i = 1; i <= 50; ++i) {
    p[i] = p[i-1] * 2 + 1;
    total[i] = total[i-1] * 2 + 3;
  }

  // cout << rec(n,x) << endl;
  printf("%lld\n", rec(n,x));
}
