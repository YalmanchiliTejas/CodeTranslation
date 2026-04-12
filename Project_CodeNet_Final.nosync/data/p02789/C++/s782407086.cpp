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

#define MX 10000000000
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
void solve()
{
   int m, n;
   cin >> m >> n;
   if (n == m)
   {
      cout << "Yes";
   }
   else
      cout << "No";
}
int main()
{
	int t = 1;
//	cin >> t;
	while (t--)
	{
		solve();
	}
}
