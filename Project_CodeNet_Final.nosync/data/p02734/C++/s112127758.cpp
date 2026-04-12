/*
Atcoder abc159F
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;

int n,s,a[3005];
int ans,f[3005];

signed main()
{
	cin>>n>>s;
	for(int i=1;i<=n;cin>>a[i++]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==s)
			ans = (ans+i*(n-i+1))%M;
		else if(a[i]<s)
		{
			ans = (ans+f[s-a[i]]*(n-i+1))%M;
			for(int j=s;j>a[i];j--)
				f[j] = (f[j]+f[j-a[i]])%M;
			f[a[i]] = (f[a[i]]+i)%M;
		}
	}
	cout<<ans%M<<endl;
	
	return 0;
}