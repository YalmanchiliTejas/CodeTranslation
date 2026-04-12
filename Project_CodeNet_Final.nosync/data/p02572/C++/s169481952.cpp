#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
 
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
	
int a[N];
int pref[N];

int32_t main() {
	fast;
	int n;
	cin>>n;
	int res = 0;
	for(int i=1; i<=n; i++) cin>>a[i];
	pref[n] = a[n];
	for(int i=n-1; i>=1; i--)
		pref[i] = (pref[i+1] + a[i])%mod;
	for(int i=1; i<n; i++)
		res += ( a[i]%mod * (pref[i+1]%mod) )%mod;
	cout<<res%mod;
}


