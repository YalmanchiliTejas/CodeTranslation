#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>

#define ll long long

using namespace std;

ll
find(vector<ll> & a, vector<ll> & sum, vector<vector<ll>> & dp, ll start, ll end) {
  if (start > end) return 0;
  if (start == end) return a[start];

  if (dp[start][end] == -1) {
    ll left = a[start] + sum[end] - sum[start] - find(a, sum, dp, start + 1, end);
    ll right = a[end] + sum[end-1] - sum[start-1] - find(a, sum, dp, start, end - 1);
    dp[start][end] = max(left, right);
  }

  return dp[start][end];
}

void
solve() {
  ll n;
  cin>>n;

  vector<ll> a(n+1), sum(n+1, 0);
  for (ll i=1; i<=n; i++) {
    cin>>a[i];
    sum[i] = sum[i-1] + a[i];
  }

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
  ll ans = find(a, sum, dp, 1, n);
  cout<< ans - (sum[n] - ans) <<endl;
}

int
main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);

  ll t = 1;
  //cin>>t;

  while (t > 0) {
    t--;
    solve();
  }

  return 0;
}

