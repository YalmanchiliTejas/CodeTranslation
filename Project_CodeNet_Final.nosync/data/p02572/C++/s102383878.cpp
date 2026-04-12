#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int lli;
#define optimize ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define F first
#define S second
#define forn(i,n) for(int i = 0; i<n; i++)
#define forab(i,a,b) for(int i = a; i<b; i++)
#define forll(i,a,b) for(lli i = a; i<b; i++)
#define mp make_pair
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define debug(x) cout<<#x<<" : "<<x<<endl
#define all(x) x.begin(),x.end()
#define printv(v) for(auto it : v) cout<<it<<" ";cout<<endl;
#define prec(n) fixed<<setprecision(n)
const lli mod1 = 1000000007;
const int mod2 = 998244353;
const int N = 1e5;

int main()
{
	optimize

	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<lli>a(n);
	forn(i,n) cin>>a[i];

	vector<lli>pref(n+1,0LL);
	forab(i,1,n+1)
		pref[i] = (pref[i-1]+a[i-1])%mod1;

	lli res = 0LL;

	forn(i,n-1)
	{
		res = (res + (a[i]*(pref[n]-pref[i+1]+mod1)%mod1)%mod1)%mod1;
	}

	cout<<res<<endl;



	return 0;
}