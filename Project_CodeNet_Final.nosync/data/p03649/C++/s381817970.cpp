#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>  
#include<cstdio>  
#include<fstream>  
#include<iomanip>
#include<algorithm>  
#include<cmath>  
#include<deque>  
#include<vector>
#include<bitset>
#include<queue>  
#include<string>  
#include<cstring>  
#include<map>  
#include<stack>  
#include<set>
#include<functional>
#define pii pair<int, int>
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define eps 0.00000001
#define mst(a,i) memset(a,i,sizeof(a))
#define all(n) n.begin(),n.end()
#define lson(x) ((x<<1))  
#define rson(x) ((x<<1)|1) 
#define inf 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll a[55];
ll tempcheck[55];
ll n;
bool check(ll t)
{
	for (int i = 1; i <= n; ++i)
		tempcheck[i] = (a[i] + t) / (n + 1LL);
	ull ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += tempcheck[i];
		if (ans > t)return 0;
	}
	if (ans < t)return 1;
	else return 0;
}
int tt[60];
bool fit(ll t)
{
	for (int i = 1; i <= n; ++i)
		tempcheck[i] = (a[i] - n + t) / (n + 1LL);
	ull ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += tempcheck[i];
	for (int i = 1; i <= n; ++i)
		tt[i] = a[i] - tempcheck[i] * (n + 1) + ans;
	int flag = 1;
	while (flag)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (tt[i] >= n)
			{
				tt[i] -= n;
				tempcheck[i]++;
				for (int j = 1; j <= n; ++j)
				{
					if (i != j)tt[j]++;
				}
			}
		}
		flag = 0;
		for (int i = 1; i <= n; ++i)
			if (tt[i] >= n)flag = 1;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += tempcheck[i];
	if (ans == t)return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j, k, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	ll l = 0, r = 1000000000000000000LL;
	while (r - l > 1)
	{
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid;
	}
	l -= 2000;
	r += 2000;
	for (ll i = max(l, 0LL); i <= r; ++i)
		if (fit(i)) { cout << i << endl; }
	return 0;
}