/*input
6
7
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/********************* MODULAR ARITHMETIC *******************************/

ll MOD = 1000000007;

void mod(ll &a){ if(a >= MOD) a %= MOD; }
ll add(ll a, ll b) { a += b; mod(a); return a; }
ll mul(ll a, ll b) { mod(a); mod(b); a *= b; mod(a); return a; }
ll sub(ll a, ll b) { mod(a); mod(b); a -= b; a += MOD; mod(a); return a; }

ll powr(ll a, ll b) {
  ll x = 1LL;
  while(b) {
    if(b & 1) x = mul(x, a);
    a = mul(a, a), b >>= 1;
  }
  return x;
}

ll inv(ll a) { return powr(a, (MOD - 2)); }

/************************************************************************/

string s;
int len;
int k;
int dp[10001][101][2];

int func(int idx, int rem, bool flag, string ans = "")
{
	if(idx == len) {
		return rem == 0;
	}

	if(dp[idx][rem][flag] > -1) {
		return dp[idx][rem][flag];
	}

	int res = 0;
	int c = 10;
	if(!flag) {
		c = s[idx] - '0';
		res = add(res, func(idx + 1, (rem + c) % k, 0));
	}

	for(int i = 0; i < c; i ++) {
		res = add(res, func(idx + 1, (rem + i) % k, 1));
	}
	return dp[idx][rem][flag] = res;
}

int main()
{
  cin >> s >> k;
  len = s.length();

  memset(dp, -1, sizeof(dp));
  ll ans = func(0, 0, 0);
  cout << sub(ans, 1);
  return 0;
}