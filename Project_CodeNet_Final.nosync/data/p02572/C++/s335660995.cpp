#pragma GCC optimize("Os") 
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#define ll long long
#define FOR(i,n) for(int i=0;i<(n);i++)
using namespace std;
const int INF = (int)1e9,mxN = (int)1e5,MOD= INF+7;

void solve()
{
	ll n;
	cin >> n;
	ll ans = 0;
	ll pref[n],a[n];
	FOR(i,n)
	{
		cin >> a[i];
		if(!i)pref[i] = a[i];
		else pref[i] = (a[i]+pref[i-1])%MOD;
	}

	FOR(i,n-1)
		ans = (ans+(a[i]%MOD*(pref[n-1]-pref[i]+MOD)%MOD)%MOD)%MOD;
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
}
