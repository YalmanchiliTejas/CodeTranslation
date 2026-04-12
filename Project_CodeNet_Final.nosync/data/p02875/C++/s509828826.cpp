#include<bits/stdc++.h> 
#define ll long long 
using namespace std;

const int maxn=1e7+10;
const int mod=998244353;
int n;
ll poww(ll x,ll k) {
	ll ans=1;
	while(k) {
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
ll mul[maxn],inv[maxn],er[maxn],ans;
ll C(int a,int b) {
	return mul[a]*inv[b]%mod*inv[a-b]%mod;
}
ll QwQ;
int main() 
{
	scanf("%d",&n);
	mul[0]=1,er[0]=1;
	for(int i=1;i<=n;++i) mul[i]=mul[i-1]*i%mod,er[i]=er[i-1]*2%mod;
	inv[n]=poww(mul[n],mod-2);
	for(int i=n;i;i--) inv[i-1]=inv[i]*i%mod;
	inv[0]=1;
	for(int i=n/2+1;i<=n;++i) {
		QwQ=(QwQ+C(n,i)*er[n-i]%mod)%mod;
	}
	cout<<(poww(3,n)-QwQ*2%mod+mod)%mod<<"\n";
	return 0;
} 
