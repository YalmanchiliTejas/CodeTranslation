#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <bitset>
#include <fstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair <int, int>
#define pll pair <long long, long long>
#define vi vector <int>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const ll inf = 1e18;

const int N = 55;
ll n, ans, a[N];

bool simple_check(ll x)
{
	ll need = 0;
	for(int i = 0; i < n; i++)
	{
		ll b = a[i] + x;
		need += b / (n + 1);
		if(b % (n + 1) == n)
			need++;
	}
	return need <= x;
}

bool check(ll x)
{
	for(ll i = x; i >= 0 && i >= x - 100; i--)
		if(simple_check(i)) return true;
	return false;
}

ll bs(ll l, ll r)
{
	if(l == r)
		return l;
	if(r == l + 1)
		if(check(l)) return l; else return r;
	ll m = (l + r) / 2;
	if(check(m)) return bs(l, m); else return bs(m, r);
}

int main()
{
	ios:: sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ans = bs(0, inf);
	//cout << "Kek" << endl;
	//for(int i = 0; i < 10; i++)
	//	cout << i << ": " << check(i) << endl;
	cout << ans;
	return 0;
}
