#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

ll calc_p(ll n) {
  return (1ll << (n+1)) - 1;
}

ll calc_total(ll n) {
  return (1ll << (n+2)) - 3;
}

ll solve(ll n, ll x) {
  if (x == 0) return 0;
  if (x == 1) return n==0 ? 1 : 0;
  ll h = calc_total(n-1);
  if (x < h+1) return solve(n-1, x-1);
  if (x == h+1) return calc_p(n-1);
  if (x == h+2) return calc_p(n-1)+1;
  if (x < 1+h+1+h+1) return calc_p(n-1) + 1 + solve(n-1, x-1-h-1);
  return 2*calc_p(n-1)+1;
}

int main()
{
  ll n,x;
  cin>>n>>x;
  cout << solve(n,x) << endl;
  return 0;
}
