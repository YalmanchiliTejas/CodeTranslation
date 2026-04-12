#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

int mod(ll n) {
  n %= MOD;
  if (n < 0) n += MOD;

  return n;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  rep(i, n) cin >> vec.at(i);
  ll ans = 0;
  vector<ll> culsum(n+1, 0);
  reps(i,1, n+1) {
    culsum.at(i) = vec.at(i-1) + culsum.at(i-1);
    culsum.at(i) %= MOD;
  }
  rep(i, n-1) {
    ans += vec.at(i) * mod(culsum.at(n) - culsum.at(i+1));
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}