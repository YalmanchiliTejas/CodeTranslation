#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define pb push_back
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define pq priority_queue<int>
#define test int tcase; cin>>tcase; for(int tc = 1; tc <= tcase; tc++)
#define inp(a,n,f) int a[n+f];for(int hh=f;hh<n+f;hh++)cin>>a[hh];
#define prdec(k) cout<<fixed<<setprecision(k);
#define mem(a,k) memset(a,k,sizeof(a))
#define ub upper_bound
#define lb lower_bound
#define mii map<int,int>
#define all(v) v.begin(),v.end()
#define inf LLONG_MAX
#define mod 1000000007


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,i,ans=0;
	cin>>n;
	inp(a,n,0);
	int suf[n];
	suf[n-1]=a[n-1];
	for(i=n-2;i>=0;i--)
		suf[i]=suf[i+1]+a[i];
	for(i=0;i<n-1;i++)
	{
		suf[i+1]%=mod;
		int temp=(a[i]*suf[i+1])%mod;
		ans=(ans+temp)%mod;
	}
	cout<<ans;
	return 0;
}
