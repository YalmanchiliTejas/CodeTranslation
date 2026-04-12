#include "bits/stdc++.h"
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 1e9 + 7;
int32_t  main()
{
	int n;
	cin >> n;
	int a[n];
	int s = 0;
	forn(i,n){
		cin>>a[i];
		s += a[i];
	}
	int suffixsum[n];
	int k =  0;
	for(int i = 0;i < n;i++)
	{
		k+= a[i];
		suffixsum[i] = (s - k) % mod;
	}
	int ans = 0;
	for(int i = 0;i < n - 1 ;i++)
	{
		int add = (a[i] * suffixsum[i]) % mod;
		ans = (ans + add) % mod;
	}
	cout<<ans;
}