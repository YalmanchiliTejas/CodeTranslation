#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>

#define mod 1000000007
#define ll long long int
#define pb(x) push_back(x)
#define MP(x,y) make_pair(x,y)

using namespace std;

ll power(ll a, ll b, ll m)
{
	if (b == 0)
		return(1);
	ll sol = power(a, b / 2, m);
	sol = (sol * sol) % m;
	if (b % 2 == 1)
		sol = (sol * a) % m;
	return(sol);
}

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
	{
		return gcd(b, a % b);
	}
}
multiset<int>m;
void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		auto it = m.lower_bound(x);
		if (it == m.begin())
			m.insert(x);
		else
		{
			it--;
			m.erase(it);
			m.insert(x);
		}
	}
	cout << m.size();
}
int main()
{
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
