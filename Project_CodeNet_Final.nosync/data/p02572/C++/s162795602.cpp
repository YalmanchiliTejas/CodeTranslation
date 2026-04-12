#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 1654378
#define int long long
using namespace std;
int a[p],s[p];
const int mods=1e9+7;
signed main()
{
	int n;
	cin>>n;
	for(fint i=1;i<=n;i++)
	cin>>a[i],s[i]=s[i-1]+a[i];
	int ans=0;
	for(fint i=1;i<n;i++)
	ans=(ans+(s[n]-s[i])%mods*(s[i]-s[i-1]))%mods;
	cout<<ans%mods;
	return 0;
}