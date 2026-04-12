
#define _USE_MATH_DEFINES

#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <utility>
#include <ctgmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf = 10e17;
const ll mod = inf;//1000000007;
const ld eps = 10e-9;



ll solve(void);
ll gcd(ll x, ll y);


ll mulmod(ll x, ll y)
{
	return (x * y) % mod;
}

ll submod(ll x, ll y)
{
	return (x - y + 100 * mod) % mod;
}

ll power(ll n, ll r)
{
	if ( r == 0 ) { return 1; }
	if ( r == 1 ) { return n; }
	if ( n == 0 ) { return 0; }
	if ( n == 1 ) { return 1; }

	if (r % 2 == 0)
	{
		ll y = power(n, r/2);
		return mulmod(y, y);
	}
	else
	{
		ll y = power(n, (r-1)/2);
		return n * mulmod(y, y) % mod;
	}
}

ll gcd(ll x, ll y)
{
	if (y == 1) { return 1;}
	if (x % y == 0) { return y; }
	return gcd(y, x % y);
}

vector<ll> perm;
vector<ll> inv;
void init_inv(ll m)
{
	perm.resize(m);
	inv.resize(m);
	
	perm[0] = 1;
	inv[0] = 1;

	for (ll i = 1; i < m; i++)
	{
		perm[i] = mulmod(perm[i-1], i);
	}
	
	for (ll i = 1; i < m; i++)
	{
		inv[i] = power(perm[i], mod - 2);
	}
}

ll ncr(ll n, ll r)
{
	// n (n-1) ... (n-r)
	if ( r == n || r == 0 ) { return 1; }

	ll ans = 1;
	//for (ll i = 0; i < r; i++)
	//	ans = mulmod(ans, n - i);

	ll p = 1;
	for (ll i = n - r + 1; i <= n; i++)
		p *= i;
	ll q = 1;
	for (ll i = 1; i <= r; i++)
		q *= i;

	return p / q;
	// return mulmod(ans, inv[r]);
	// return mulmod(perm[n], mulmod(inv[n-r], inv[r]));
}

bool binary_check(ll mid, ll key)
{
	return mid >= key;
}

ll binary_search()
{
	ll n, k;
	cin >> n >> k;

	ll ng = 0;
	ll ok = n;

	while (abs(ok - ng) > 1)
	{
		ll mid = (ok+ng) / 2;
		if (binary_check(mid, k)) ok = mid;
		else ng = mid;
	}

	return ok;
}

string s;
ll k, l;


ll calc(ll digit, ll k, bool smaller)
{
	if (digit == l) {
		if (k == 0) return 1;
		else return 0;
	}
	if (k == 0) return 1;
	if (smaller) 
	{
		return ncr(l - digit, k) * power(9, k);
	}
	if(s[digit] == '0') return calc(digit+1, k, false);
	ll zero = calc(digit + 1, k, true);
	ll bet  = calc(digit + 1, k - 1, true) * (s[digit] - 1 - '0');
	ll giri = calc(digit + 1, k - 1, false);
	return zero + bet + giri;
}

ll solve(void)
{
	init_inv(1000);
	cin >> s;
	cin >> k;
	l = s.length();

	cout << calc(0, k, false) << endl;
	return 0;
}

int main(void)
{
	while (solve())
	{
	}
	return 0;
}
