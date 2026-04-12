#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll m,n,k;
ll ksm(int x,int k)
{
	if(k==1) return x;
	ll ans=ksm(x,k/2);
	ans=(ans*ans)%mod;
	if(k%2) ans=ans*x%mod;
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	ll i,j;
	ll cnt=0,cnt2=0,s=0,ans=0;;
	cnt=n*n;
	cnt%=mod;
	for(i=1;i<=m;i++) 
	s=(s+i*(m-i))%mod;
	cnt=(cnt*s)%mod;
	
	cnt2=m*m;
	cnt2%=mod;
	s=0;
	for(i=1;i<=n;i++)
	s=(s+i*(n-i))%mod;
	cnt2=(s*cnt2)%mod;
	
	ans=(cnt+cnt2)%mod;
	ll p=n*m-2;
	for(i=p;i>p-k+2;i--)
	ans=(ans*(i%mod))%mod;
	
	ll q=1;
	for(i=1;i<=k-2;i++) q=(q*(i%mod))%mod;
	
	q=ksm(q,mod-2);
	ans=ans*q%mod;
	cout<<ans;
	return 0;
 } 