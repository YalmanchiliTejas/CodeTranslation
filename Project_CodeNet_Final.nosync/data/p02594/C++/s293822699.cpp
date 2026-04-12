#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ff		first
#define sd      second
#define mod 	1000000007
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define inf 	1e18
#define vi          vector<int>
#define pb  	push_back
#define full(x) x.begin(), x.end()
#define int 	long long
#define pq 	priority_queue<int,int>
#define ford(i, a, b) for (int i=a; i<(b); i++)
#define foro(i, a) for (int i=0; i<(a); i++)
#define w(t)	int t; cin>>t; while(t--)

const int N = 1e5 + 5;



using namespace std;

#define IOS ios:: sync_with_stdio(0);cin.tie(0); cout.tie(0);


void abc()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int pow(int n, int p, int md)
{
	int ans  = 1;

	while (p > 0)
	{
		int last = (p & 1);
		if (last == 1)
		{
			ans = (ans * n) % md ;
		}
		n = (n * n) % md;
		p = p >> 1;
	}

	return ans;
}
int x, y, GCD;
void ExtendedEuclid(int a, int b)
{
	if (b == 0)
	{
		y = 0;
		x = 1;
		GCD = a;
		return;
	}

	ExtendedEuclid(b, a % b);
	int cx = y;
	int cy = x - (a / b) * y;

	x = cx;
	y = cy;
}

int inv(int n, int md)
{
	ExtendedEuclid(n, md);
	return (x + md) % md;
}
int fact[2000005];
void facto()
{
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 2000005; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod ;
	}
}
int lucas(int a, int md)
{
	return pow(a, md - 2, md);
}

void solve()
{
	//Code here;
	int x;
	cin >> x;

	if (x >= 30)
	{
		cout << "Yes" << endl;
	} else
	{
		cout << "No" << endl;
	}


}
int32_t main()
{
	IOS;



	solve();


	return 0;
}