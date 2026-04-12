#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// #define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define vvv64 vector<vv32>
#define vvvv64 vector<vvv32>
ll exp(ll n, ll e)
{
    if (e==0)
        return 1;
    ll temp=exp((n*n)%MOD,e/2);
    return e%2==0 ? temp : (temp*n)%MOD;
}
bool check(string s)
{
	for (int i=0; i<sz(s); i++)
	{
		if (s[i]!=s[sz(s)-i-1])
			return false;
	}
	return true;
}
int LIM=3010;
vv64 dp(LIM,v64(LIM,0));
void solve()
{
//Read Comments below main
	ll n,s;
	cin>>n>>s;
	v64 arr(n+1,0);
	for (int i=1; i<=n; i++)
		cin>>arr[i];
	for (int i=1; i<=n; i++)
	{
		dp[i][arr[i]]=i;
		for (int j=1; j<=s; j++)
		{	
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=MOD;
			if (j>=arr[i])
				dp[i][j]+=dp[i-1][j-arr[i]];
			dp[i][j]%=MOD;
		}
	}
	ll ans=0;
	for (int i=1; i<=n; i++)
	{
		ll temp=dp[i][s]-dp[i-1][s]+MOD;
		temp%=MOD;
		temp=(temp*(n-i+1))%MOD;
		ans=(ans+temp)%MOD;
	}
	cout<<ans<<endl;
}
 
int main() {
    fast_cin();
    ll t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
// BITMASK:
// 1)When some constraint is of the order of 15-20, think of bitmask DP.
// 2)When some constraint is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algo