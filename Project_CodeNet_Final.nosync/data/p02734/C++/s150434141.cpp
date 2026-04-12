#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline void Add(int &a,int b){a=a+b>=mod?a+b-mod:a+b;}
int n,a[3010],s,ans=0;
int f[3010][3010];
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=3000;j++)
	{
		if(j==a[i]) Add(f[i][j],i);
		Add(f[i][j],f[i-1][j]);
		if(j>=a[i]) Add(f[i][j],f[i-1][j-a[i]]);
		if(j==s) Add(ans,1ll*(f[i][j]+mod-f[i-1][j])%mod*(n-i+1)%mod);
	}
	cout<<ans<<endl;
}