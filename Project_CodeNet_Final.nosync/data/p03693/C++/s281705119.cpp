#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 10001
/*
ll power(ll n, ll to)
{
	if (to == 0) return 1;
	if (to == 1) return n;
	int exp = 1;
	ll ans = n;
	while (2 * exp <= to)
	{
		ans *= ans;
		ans %= mod;
		exp *= 2;
	}
	return ((ans*power(n, to - exp)) % mod);
}

ll gcd(ll a, ll b)
{
	if (a < b)
		swap(a, b);

	if (b == 0)
		return a;

	if (a < b)
		swap(a, b);

	return gcd(b, a%b);
}

pll add(int a, int b)
{
	if (a > b)
		swap(a, b);

	ll mult = 1;
	FOR(i, a, b + 1)
	{
		mult *= i;
		mult %= mod;
	}

	ll num = 0;
	FOR(i, a, b + 1)
	{
		num += (mult * power(i, mod - 2));
		num %= mod;
	}

	return MP(num, mult);
}

ll n;
vll a, b;

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	cin >> n;
	a.assign(n, 0);
	b.assign(n - 1, 0);
	FOR(i, 0, n)
		cin >> a[i];

	FOR(i, 0, n - 1)
		cin >> b[i];

	sort(ALL(a));

	if (n == 2)
	{
		ll p, q;

		p = b[0];
		q = a[1] - a[0];

		auto sum = add(a[0] + 1, a[1]);
		
		p *= sum.first;
		q *= sum.second;
		p %= mod;
		q %= mod;

		ll res = p % mod;
		res *= power(q, mod - 2);
		cout << res%mod;
	}
	else
	{
		if (n == 3)
		{
			pll c1, c2, c3;
			c2.X = a[1] * b[1] - b[0];
			c2.Y = (a[2] - a[1])*(a[1] - a[0]);

			c1.X = a[0] * b[1] - b[0];
			c1.Y = (a[2] - a[0])*(a[0] - a[1]);

			c1.X %= mod;
			c1.Y %= mod;
			c2.Y %= mod;
			c2.X %= mod;

			c3.Y = c1.Y * c2.Y;
			c3.X = mod * mod - (c1.Y * c2.X + c1.X * c2.Y);

			c3.X %= mod;
			c3.Y %= mod;




		}
	}
	

	
	return 0;
}*/

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int r, g, b;
	cin >> r >> g >> b;

	int x = 10 * g + b;
	if (x % 4 == 0)
		cout << "YES";
	else
		cout << "NO";



	return 0;
}