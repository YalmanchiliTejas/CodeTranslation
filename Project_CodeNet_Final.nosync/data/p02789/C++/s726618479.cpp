#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

#define ll long long
#define ull unsigned long long

#define	max	1000000007

class mod
{
public:
	ll val;

	mod(ll v)
	{
		val = v % max;
	}

	mod()
	{
		val = 0;
	}

	void operator -=(const mod &v)
	{
		val -= v.val;

		if (val < 0)
			val += max;
	}

	void operator +=(const mod &v)
	{
		if (val + v.val >= max)
			val -= max;
		val += v.val;
	}

	void operator +=(ll &v)
	{
		if (val + v >= max)
			val -= max;
		val += v;
	}

	void operator *=(const mod &v)
	{
		val *= v.val;
		val %= max;
	}

	void operator *=(ll &v)
	{
		val *= v;
		val %= max;
	}

	ll modinv(ll a)
	{
		ll b = max, u = 1, v = 0;
		while (b)
		{
			ll t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		u %= max;
		if (u < 0)
			u += max;
		return u;
	}

	void operator /=(const mod &v)
	{
		val *= modinv(v.val);
		val %= max;
	}

	void operator /=(ll &v)
	{
		val *= modinv(v);
		val %= max;
	}
};

int main()
{
	int n, m;
	cin >> n>> m;
	if (n == m)
		printf("Yes");
	else
		printf("No");

	//printf("%d", r);
	return 0;
}
