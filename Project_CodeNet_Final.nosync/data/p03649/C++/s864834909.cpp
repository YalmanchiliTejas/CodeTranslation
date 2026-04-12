/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 60;
const ll inf = 1e18;

ll a[N];

ll ceil_div(ll x, ll y);

int main()
{
	int n;
	cin >> n;
	priority_queue <ll> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		q.push(a[i]);
	}

	ll s = 0;
	while (q.top() > n - 1 - s)
	{
		ll cur = q.top();
		q.pop();
		ll p = ceil_div(cur - n + s + 1, n + 1);
		cur -= p * (n + 1);
		s += p;
		q.push(cur);
	}

	cout << s << endl;
}

ll ceil_div(ll x, ll y)
{
	return (x / y) + !!(x % y);
}