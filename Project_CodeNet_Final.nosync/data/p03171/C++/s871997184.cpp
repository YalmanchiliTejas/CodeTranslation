#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
vector<vector<ll>> dp;
ll inf = 1000000000000000;
vector<ll> a;

ll rec(int l = 0, int r = n) {
  if (l == r) return 0;

  if (dp[l][r] != inf) return dp[l][r];

  if ((n - (r - l)) % 2 == 0) {
    dp[l][r] = max(rec(l,r-1) + a[r-1], rec(l+1,r) + a[l]);
  } else {
    dp[l][r] = min(rec(l,r-1) - a[r-1], rec(l+1,r) - a[l]);
  }

  return dp[l][r];
}

int main() {
  cin >> n;
  a.resize(n);
  rep(i,0,n) cin >> a[i];
  dp.assign(n+2, vector<ll>(n+2,inf));
  rep(i,0,n) dp[i][i] = 0;
  cout << rec() << endl;
  return 0;
}
