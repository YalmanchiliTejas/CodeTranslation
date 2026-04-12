#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define all(c) (c).begin(),(c).end()
#define ss second
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> > 
#define vvpi vector<vector<pair<int,int> > >
#define Inp(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define Out(a,n,ch) for(int i=0;i<n;i++)cout<<a[i]<<ch;cout<<endl;
 
int a[200005],pref[200005]={0};
int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	
	int n,sum=0,cursum=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=n-2;i>=0;i--)
	{
		pref[i] = pref[i+1] + a[i+1];
	}

	for(int i=0;i<n-1;i++)
	{
		ans = (ans+(pref[i]%MOD*a[i]%MOD))%MOD;
	}
	cout<<ans<<endl;
	
	return 0;
}