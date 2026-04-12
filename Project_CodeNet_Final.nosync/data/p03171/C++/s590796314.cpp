/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <ll , ll>;
void in(ll &x);
const ll N = 3005;
ll n;
ll a[N], dp[N][N];

ll f(ll l , ll r) {
  if (l > r) return 0;
  ll &sol = dp[l][r];
  if (sol != -1) return sol;
  sol = a[l] - f(l + 1 , r);
  sol = max(sol , a[r] - f(l , r - 1));
  return sol;
}

int main() {
  in(n);
  for (ll i = 1 ; i <= n ; i++) {
    in(a[i]);
  }
  memset (dp , -1 , sizeof dp);
  printf("%lld\n" , f(1 , n));
  return 0;
}

void in(ll &x){
	bool neg = false;
	register ll c;
	x = 0;
	c = getchar();
	if(c == '-'){
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
