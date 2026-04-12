#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[8] = {-1,0,1,-1,1,-1,0,1};
int sj[8] = {-1,-1,-1,0,0,1,1,1};

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> s(n-1, a[0]);
  rep(i,n-2) s[i+1] = (s[i] + a[i+1])%M;

  ll ans = 0;
  for (int i = 1; i <n; i++){
    ans += (a[i] * s[i-1])%M;
    ans %= M;
  }
  cout << ans << endl;
  return 0;
}
