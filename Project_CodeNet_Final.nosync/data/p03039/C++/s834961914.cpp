#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const ll mod=1e9+7;
ll xs1;
ll xs2;
ll n,m;
ll k;
ll jiec[1000005];
ll ksm(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=mod;
		x*=x;x%=mod;
		y>>=1;
	}
//	cout<<ans<<endl;
	return ans;
}
ll C(ll x,ll y)//左上 
{
	return jiec[y]*ksm(jiec[x],mod-2)%mod*ksm(jiec[y-x],mod-2)%mod;
}
int main(){
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n-1;i++)
	{
		xs1+=i*(n-i);
		xs1%=mod;
	}
	xs1*=m;
	xs1%=mod;
	xs1*=m;
	xs1%=mod;
	for(int i=1;i<=m-1;i++)
	{
		xs2+=i*(m-i);
		xs2%=mod;
	}
	xs2*=n;
	xs2%=mod;
	xs2*=n;
	xs2%=mod;
	jiec[0]=1;
//	xs1*=ksm(2,mod-2);
//	xs2*=ksm(2,mod-2);
//	xs1%=mod;
//	xs2%=mod;
//	cout<<xs1<<" "<<xs2<<endl;
	for(int i=1;i<=200000;i++)
	{
		jiec[i]=jiec[i-1]*i;
		jiec[i]%=mod;
	}
	xs1+=xs2;
	xs1%=mod;
	xs1*=C(k-2,n*m-2);
	xs1%=mod;
	cout<<xs1<<endl;
	return 0;
}