#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define mp make_pair
#define pb push_back
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)  ((a)*((b)/gcd(a,b)))
#define pi 3.14159265358979323846
#define mod 1000000007
#define reus ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int32_t main()
{
	reus;
	
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	
	int n,i;
	cin>>n;
	vector<int> a(n),b(n,0);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i+1]=b[i]+a[i];
	}
	int ans=0,k=0;
	for(i=0;i<n;i++)
	{
		k=a[i]*((b[n]-b[i+1])%mod);
		ans+=k;
		ans=ans%mod;
	}
	cout<<ans<<endl;
	return 0;
}