#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

typedef vector<ll> vecll;
typedef vector<ld> vecld;
typedef vector<bool> vecbl;
typedef vector<vector<ll> > matll;
typedef vector<vector<ld> > matld;
typedef vector<vector<bool> > matbl;
#define mp make_pair;

const ll prime = 1000000000 + 7;
const ld PI = 2 * acos(0.0);

/*
cout << fixed << setprecision(10);
*/

bool my_comp(pll a, pll b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}

	return a.second < b.second;
}

// nのk乗(mod p = prime)
ll power(ll n, ll k) {
	ll p = prime;
	if (k == 1) {
		return n;
	}
	ll m = n * n;
	m %= p;
	if (k % 2 == 0) {
		return power(m, k / 2);
	}
	m = power(m, k / 2);
	m *= n;
	m %= p;
	return m;
}

// nCk(mod p = prime)
ll com(ll n, ll k) {
	// nCk
	ll p = prime;

	ll ans = 1;
	for (ll i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= p;
	}

	for (ll i = 2; i <= k; i++)
	{
		ans *= power(i, p - 2);
		ans %= p;
	}

	for (ll i = 2; i <= n-k; i++)
	{
		ans *= power(i, p - 2);
		ans %= p;
	}

	return ans;
}

vector<pll> pfac(ll n) {
	// prime factorization
	ll m = n;
	vecll primes;
	for (ll i = 2; i <= n; i++)
	{
		if (m % i == 0) {
			while (true) {
				primes.push_back(i);
				m /= i;
				if (m % i == 0) {
					continue;
				}
				else {
					break;
				}
			}
		}
		if (m == 1) {
			break;
		}
	}

	vector<pll> primep;
	ll pre, now, index;
	pre = -1;
	index = 0;
	for (ll i = 0; i < primes.size(); i++)
	{
		now = primes[i];
		if (pre == now) {
			primep[index].second++;
		}
		else {
			index++;
			primep.push_back(make_pair(now, 1));
			pre = now;
		}
	}

	return primep;

}

vecll divisors(vector<pll> primep) {
	vecll primes, primes2;
	for (ll j = 0; j < primep[0].second; j++)
	{
		primes.push_back(pow(primep[0].first, j));
	}

	for (ll i = 1; i < primep.size(); i++)
	{
		primes2 = vecll();
		for (ll j = 0; j < primes.size(); j++)
		{
			for (ll k = 0; k < primep[i].second; k++)
			{
				primes2.push_back(primes[j] * pow(primep[i].first, k));
			}
		}
		primes = vecll();
		for (ll i = 0; i < primes2.size(); i++)
		{
			primes[i] = primes2[i];
		}
	}

	return primes;
}

int gcd(int a1, int b1) {
	int a, b;
	a = max(a1, b1);
	b = min(a1, b1);
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

ll gcd(ll a, ll b, ll c) {
	return gcd(gcd(a, b), c);
}


int main() {
	//
	ll n;
	cin >> n;
	vecll a(n), dp0, dp1, dp2;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (n % 2 == 0) {
		dp0 = vecll(n / 2);
		dp1 = vecll(n / 2);
		// dp0 : 次取れる
		// dp1 : 次取れない
		dp0[0] = a[0];
		dp1[0] = a[1];
		for (ll i = 1; i < n/2; i++)
		{
			dp0[i] = dp0[i - 1] + a[i * 2];
			dp1[i] = max(dp0[i - 1], dp1[i - 1]) + a[i * 2 + 1];
		}
		cout << max(dp0[n/2-1], dp1[n/2-1]) << endl;
		return 0;
	}

	dp0 = vecll(n / 2 + 1); // 一つ少ない, 次取れない
	dp1 = vecll(n / 2 + 1); // 一つ少ない, 次取れる
	dp2 = vecll(n / 2 + 1); // 多めに取る, 次取れない

	dp0[0] = 0;
	dp1[0] = 0;
	dp2[0] = a[0];

	for (ll i = 1; i < n/2+1; i++)
	{
		dp0[i] = max(dp0[i - 1], dp1[i - 1]) + a[i * 2];
		dp1[i] = max(dp1[i - 1] + a[i * 2 - 1], dp2[i-1]);
		dp2[i] = dp2[i - 1] + a[i * 2];
	}

	cout << max(dp0[n/2], dp1[n/2]) << endl;


	return 0;
}
