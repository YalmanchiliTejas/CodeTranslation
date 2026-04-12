#include<bits/stdc++.h>
#define P 998244353
#define N 160005
#define ll long long
using namespace std;
char S1[N],S2[N];
ll pw(ll a,ll b,ll c)
{
	ll ans=1;
	for (;b;a=(ll)a*a%c,b>>=1)
		if (b&1) ans=(ll)ans*a%c;
	return ans;
}
 
ll tl,tn,w[2][N],r[N],rn,ans[N];
void pre(ll x)
{
	tl=0;tn=1;
	while(tn<=x)tn<<=1,tl++;
	tn<<=1;tl++;
	ll W=pw(3,(P-1)/tn,P);
	w[0][0]=w[1][0]=1;
	for (ll i=1;i<tn;i++)
		w[0][i]=(ll)w[0][i-1]*W%P;
	for (ll i=1;i<tn;i++)
		w[1][i]=w[0][tn-i];
	for (ll i=1;i<tn;i++)
		r[i]=(r[i>>1]>>1)|((i&1)<<(tl-1));
	rn=pw(tn,P-2,P);
}
 
void dft(ll *a,ll f)
{
	for (ll i=0;i<tn;i++)
		if(i<r[i]) swap(a[i],a[r[i]]);
	for(ll i=1;i<tn;i<<=1)
	for(ll j=0,t=tn/(i<<1);j<tn;j+=i<<1)
	for(ll k=0,l=0;k<i;k++,l+=t)
	{
		ll x=(ll)w[f][l]*a[j+k+i]%P;
		ll y=a[j+k];
		a[j+k]=(y+x)%P;
		a[j+k+i]=(y+P-x)%P;
	}
	if(f)
		for (ll i=0;i<tn;i++)
			a[i]=(ll)a[i]*rn%P;
}
 
ll fac[N],ifac[N],inv[N],f[N];
void mul(ll a[],ll b[],ll c[],ll t)
{
	static ll A[N],B[N],C[N];
	for (ll i=0;i<tn;i++)
	{
		A[i]=b[i];
		B[i]=c[i];
	}
	dft(A,0);
	dft(B,0);
	for (ll i=0;i<tn;i++)
	{
		C[i]=(ll)A[i]*B[i]%P;
	}
	dft(C,1);
	for (ll i=0;i<tn;i++)
		a[i]=i<=t?C[i]:0;
}
int main()
{
	scanf("%s%s",S1,S2);
	ll n=strlen(S1);
	ll a=0,b=0;
	for (ll i=0;i<n;i++)
	{
		if (S1[i]=='1'&&S2[i]=='1') b++;
		else if (S1[i]=='1') a++;
	}
	fac[0]=inv[1]=fac[1]=ifac[1]=ifac[0]=1;
	for (ll i=2;i<=a+b+1;i++)
	{
		inv[i]=(ll)(P-P/i)*inv[P%i]%P;
		fac[i]=(ll)fac[i-1]*i%P;
		ifac[i]=(ll)ifac[i-1]*inv[i]%P;
	}
	for (ll i=0;i<=b;i++)
	{
		f[i]=ifac[i+1];
		//cout<<f[i]<<endl;
	}
	ans[0]=1;
	pre(b);
	for (ll i=a;i;i>>=1,mul(f,f,f,b))
		if (i&1) mul(ans,ans,f,b);
	
	ll Ans=0;
	for (ll i=0;i<=b;i++)
		Ans=(Ans+ans[i])%P;
	//cout<<Ans<<endl;
	Ans=(ll)Ans*fac[a]%P*fac[b]%P*fac[a+b]%P;
	printf("%lld\n",(Ans+P)%P);
	
}