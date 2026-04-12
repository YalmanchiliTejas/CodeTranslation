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

using namespace std;
const ll maxn=2e4+100,inf=1e9,LOG=23,mod=1e9+7;
int block = 300, timer = 0;
const ld EPS = 1e-7;

#define bt(i) (1 << (i))
#define int ll
#define pii pair <int, int>

int n, d, p[maxn][11], dp[maxn][110], al[maxn][110];

main()
{
	string s;
	cin >> s >> d;
	forn(0, i, 9)
	{
		dp[1][i % d]++;
	}
	forn(2, i, 10000)
	{
		forn(0, os, d - 1)
		{
			forn(0, j, 9)
			{
				dp[i][(os + j) % d] += dp[i - 1][os];
				dp[i][(os + j) % d] %= mod;
			}
		}
	}
	n = s.size();
	s = '#' + s;
	int T = 0;
	int ans  = 0;
	forn(1, i, n - 1)
	{
		forn(0, j, s[i] - '0' - 1)
		{
			/*int S = d - j - T;
			while(S < 0)
			{
				S += d;
			}*/
			ans += dp[n - i][(d - j + d - T) % d];
			ans %= mod;
		}
		T += s[i] - '0';
		T %= d;
	}
	forn(0, i, s[n] - '0')
	{
		if((i + T) % d == 0)
		{
			ans++;
			ans%=mod;
		}
	}
	cout << (ans - 1 + mod) % mod;
}