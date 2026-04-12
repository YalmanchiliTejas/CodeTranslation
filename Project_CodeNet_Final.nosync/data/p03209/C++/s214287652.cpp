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

vector<ll> a(51), p(51);

ll recursive(ll n, ll x) {
  if (n == 0) return (x > 0) ? 1 : 0;
  if (x <= 1 + a[n-1]) return recursive(n-1, x-1);
  else if (x > 1 + a[n-1]) return p[n-1] + 1 + recursive(n-1, x - a[n-1] - 2);
}

int main() {
  ll n,x;
  cin >> n >> x;

  a[0] = p[0] = 1;
  rep(i,n) {
    a[i+1] = a[i] * 2 + 3;
    p[i+1] = p[i] * 2 + 1;
  }

  printf("%lld\n", recursive(n,x));
}
