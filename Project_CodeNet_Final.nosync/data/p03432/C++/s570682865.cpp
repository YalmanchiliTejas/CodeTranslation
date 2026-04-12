#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=33e3,mo=998244353,ZD=32768;

ll f[N],g[N],t[N],bits[N];
ll w[N],ny[N],jc[N];
int n,m,ss,mm;

inline ll ksm(ll o,ll t)
{
	ll y=1;
	for(;t;t>>=1,o=o*o%mo)
	if(t&1)y=y*o%mo;
	return y;
}

inline void prepare()
{
	fo(i,0,mm-1)bits[i]=(bits[i>>1]>>1)|((i&1)<<(ss-1));
	w[0]=1; w[1]=ksm(3,(mo-1)/ZD);
	fo(i,2,ZD)w[i]=w[i-1]*w[1]%mo;
}

inline ll C(ll a,ll b)
{return jc[a]*ny[b]%mo*ny[a-b]%mo;}

inline void dft(ll *a,int sig)
{
	fo(i,0,mm-1)if(bits[i]<i)swap(a[bits[i]],a[i]);
	for(int m=2,D=ZD>>1;m<=mm;m<<=1,D>>=1){
		int half=m>>1;
		fo(i,0,half-1){
			ll v=(sig==1)?(w[D*i]):(w[ZD-D*i]),u;
			for(int j=i;j<mm;j+=m){
				u=v*a[j+half]%mo;
				a[j+half]=(a[j]-u+mo)%mo;
				a[j]=(a[j]+u)%mo;
			}
		}
	}
	if(sig==-1){
		ll nn=ksm(mm,mo-2);
		fo(i,0,mm-1)a[i]=a[i]*nn%mo;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	f[0]=jc[0]=ny[0]=1;
	fo(i,1,n+2)jc[i]=jc[i-1]*i%mo;
	ny[n+2]=ksm(jc[n+2],mo-2);
	fd(i,n+1,1)ny[i]=ny[i+1]*(i+1)%mo;
	ss=0,mm=1;
	while(mm<=2*n)mm<<=1,++ss;
	prepare();
	fo(j,1,m){
		fo(i,0,mm-1)t[i]=g[i]=0;
		fo(i,0,n)t[i]=f[i]*ny[i]%mo;
		fo(i,1,n)g[i]=ny[i+2];
		dft(t,1);	dft(g,1);
		fo(i,0,mm-1)g[i]=t[i]*g[i]%mo;
		dft(g,-1);
		fo(i,1,n)g[i]=g[i]*jc[i+2]%mo;
		fo(i,1,n)f[i]=(g[i]+f[i]*(C(i+1,2)+1))%mo;
	}
	ll ans=1;
	fo(i,1,n)ans=(ans+f[i]*C(n,i))%mo;
	cout<<ans;
}