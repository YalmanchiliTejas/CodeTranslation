#include <bits/stdc++.h>
#include <random>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define all(v) v.begin(), v.end()
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>


using namespace std;
const ll maxn=2e5+100,inf=1e18,LOG=23,mod=1e9+7;
int block = 300, timer = 0;
const ld EPS = 1e-7;

#define bt(i) (1 << (i))
#define int ll

int n, a[maxn], ans = -1e18, pref[maxn][3], suff[maxn][3];

main()
{
	IOS
	cin >> n;
	forn(1, i, n)
	{
		cin >> a[i];
	}
	for(int i = 2; i <= n; i += 2)
	{
		pref[i][0] = pref[i - 2][0] + a[i - 1];
		pref[i][1] = max(pref[i - 2][0], pref[i - 2][1]) + a[i];
	}
	for(int i = n - 1; i >= 1; i -= 2)
	{
		suff[i][1] = suff[i + 2][1] + a[i + 1];
		suff[i][0] = max(suff[i + 2][1], suff[i + 2][0]) + a[i];
	}
	if(n % 2 == 0)
	{
		cout << max(pref[n][1], pref[n][0]);
	}
	else
	{
		for(int i = 1; i <= n; i += 2)
		{
			ans = max(max(pref[i - 1][0], pref[i - 1][1]) + max(suff[i + 1][1], suff[i + 1][0]), ans);
		}
		cout << ans;
	}
}