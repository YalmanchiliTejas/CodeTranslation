#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m;
ll jc[101010],jc_ny[101010];
ll f[220][8080];
ll Power(ll x,ll k)
{
	ll sss=1;
	while (k)
	{
		if (k%2) sss=sss*x%mod;
		x=x*x%mod;
		k/=2;
	}
	return sss;
}
ll ny(ll x){return Power(x,mod-2);}
 
struct Poly
{
	ll A[202020],B[202020],C[202020];
	ll g[202020];
	int rev[202020];
	int len,kkk;
	void NTT(ll P[],ll type)
	{
		for (int i=0;i<len;++i) if (i<rev[i]) swap(P[i],P[rev[i]]);
		for (int i=2;i<=len;i<<=1)
		{
			int num=i/2;
			g[0]=1; g[1]=Power(3,(mod-1)/i); 
			if (type==-1) g[1]=ny(g[1]);
			for (int j=2;j<num;++j) g[j]=g[j-1]*g[1]%mod;
			
			for (int j=0;j<len;j+=i)
				for (int k=0;k<num;++k)
				{
					ll x=P[j+k],y=P[j+k+num]*g[k]%mod;
					P[j+k]=(x+y)%mod;
					P[j+k+num]=(x-y+mod)%mod;
				}
		}
		if (type==-1)
		{
			ll doe=ny(len);
			for (int i=0;i<len;++i) P[i]=P[i]*doe%mod;
		}
	}
	void mul(const vector<ll>a , const vector<ll>b , vector<ll> &c)
	{
		int lena=a.size(),lenb=b.size(),lenc=lena+lenb-1; 
		len=1,kkk=0;
		while (len<=lenc) len*=2,++kkk;
		for (int i=0;i<len;++i) rev[i]=(rev[i>>1]>>1) | ((i&1)<<(kkk-1));
 
		for (int i=0;i<len;++i) A[i]=B[i]=0;
		for (int i=0;i<lena;++i) A[i]=a[i];
		for (int i=0;i<lenb;++i) B[i]=b[i];
 
		NTT(A,0); NTT(B,0);
		for (int i=0;i<len;++i) C[i]=A[i]*B[i]%mod;
		NTT(C,-1);
		c.clear();
		for (int i=0;i<lenc;++i) c.push_back(C[i]);
	}
}S;
ll C(int x,int y)
{
	if (y>x || y<0) return 0;
	if (y==x || y==0) return 1;
	return jc[x] *jc_ny[x-y]%mod *jc_ny[y]%mod;
}
void init()
{
	jc[0]=jc_ny[0]=1;
	for (int i=1;i<=100010;++i) jc[i]=jc[i-1]*i%mod,jc_ny[i]=ny(jc[i]);
}
vector<ll> F1,F2,G;
int main()
{
	init();
 
	scanf("%d%d",&n,&m);
	F1.resize(n+1); F2.resize(n+1);
	f[0][0]=1;
	for (int i=0;i<m;++i) 
	{	
		for (int j=0;j<=n;++j) F1[j]=f[i][j]*jc_ny[j]%mod;
		for (int j=0;j<=n;++j) F2[j]=jc_ny[j+2];
		F2[0]=0;
 
		S.mul(F1,F2,G);
		for (int j=0;j<=n;++j) f[i+1][j]=G[j]*jc[j+2]%mod;
 
		for (int j=0;j<=n;++j)
			(f[i+1][j]+=(C(j+1,2)+1) * f[i][j]%mod )%=mod;
	}
	ll ans=0;
	for (int i=0;i<=n;++i) ( ans+= f[m][i]*C(n,i)%mod )%=mod;
	printf("%lld\n",ans);
	return 0;
}