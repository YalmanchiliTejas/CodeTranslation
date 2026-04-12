#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const int N = 3005;
const ll mod = 998244353;
ll ans=0,f[N][N];
int main()
{
	int n,s,a[N];	
	cin>>n>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=s;j++)f[i][j]=f[i-1][j];
		f[i][a[i]]=(f[i][a[i]]+i)%mod;
		for(int j=0;j+a[i]<=s;j++)
		f[i][j+a[i]]=(f[i][j+a[i]]+f[i-1][j])%mod; 
		ans=(ans+f[i][s])%mod;
	}
	cout<<ans<<endl;
	return 0;
}