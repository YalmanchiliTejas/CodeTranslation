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
typedef pair<ll,ll> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
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
void solve()
{
	string s;
	cin>>s;
	int n=s.length();
	s="a"+s;
	int d;
	cin>>d;
	ll sum=0;
	vv64 dp(n+1,v64(d+1,0));
	// dp[0][0]=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=9; j++)
		{
			for (int k=0; k<d; k++)
			{
				dp[i][(k+j)%d]+=dp[i-1][k];
				dp[i][(k+j)%d]%=MOD;
			}
		}
		int num=s[i]-'0';
		for (int j=0; j<num; j++)
		{
			dp[i][(sum+j)%d]++;
			dp[i][(sum+j)%d]%=MOD;
		}
		sum=(sum+s[i]-'0')%d;
	}
	dp[n][sum%d]++;
	dp[n][sum%d]%=MOD;
	cout<<(dp[n][0]-1+MOD)%MOD<<endl;

}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;   
} 