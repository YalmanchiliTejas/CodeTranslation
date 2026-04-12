#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;


long long modInverse(long long a, int m)
{
	long long m0 = m;
	long long y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient
		int q = a / m;
		int t = m;

		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + a[i];
		s = s % mod;
	}
	long long p = ((s) * (s )) % mod;
	long long x = 0;
	for (int i = 0; i < n; i++)
	{
		x += a[i] * a[i];
		x = x % mod;
	}
	cout << ((((p - x) * 500000004) % mod) + mod ) % mod ;
	return 0;
}