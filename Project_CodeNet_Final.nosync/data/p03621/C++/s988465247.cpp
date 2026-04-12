#include<bits/stdc++.h>
#define inv(x) qpow(x,mod-2)
using namespace std;
typedef long long ll;

const int N = 5e4+1;
const ll mod = 998244353;
const ll G = 3;
const double pi = acos(-1);

char a1[N],b1[N];
int x,y;
ll rev[N],fac[N],r[N];
ll a[N],b[N],c[N],d[N];

int qpow(ll a,int b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=(ret*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ret;
}

void pre()
{
	ll i;
	for(i=1,fac[0]=1;i<N;++i)fac[i]=(fac[i-1]*i)%mod;
	for(rev[N-1]=inv(fac[N-1]),i=N-2;i>=0;--i)rev[i]=(rev[i+1]*(i+1))%mod;
}

inline void ntt(ll *a,int f,ll n)
{
    for(int i=0;i<n;i++)if(i<r[i])swap(a[i],a[r[i]]);
    for(int i=1,t=1;i<n;i<<=1,++t)
    {
        ll wn=qpow(G,(mod-1)/(1<<t));
        if(f==-1) wn=inv(wn);
        for(int j=0;j<n;j+=(i<<1))
        for(ll k=0,w=1;k<i;k++,w=w*wn%mod)
        {
            ll x=a[j+k],y=a[j+k+i]*w%mod;
            a[j+k]=(x+y)%mod;a[j+k+i]=(x-y+mod)%mod;
        }
    }
}

void NTT(ll *a,ll *b,ll len,bool tag)
{
	ll n=1,m=0;
	while(n<=2*len)n<<=1,m++;
	for(int i=0;i<n;++i)r[i]=r[i>>1]>>1|(1&i)<<(m-1);
	copy(a,a+x+1,c);copy(b,b+x+1,d);
	for(int i=x+1;i<N;++i)a[i]=b[i]=c[i]=d[i]=0;
	ntt(c,1,n);ntt(d,1,n);
	for(int i=0;i<n;++i)(c[i]*=d[i])%=mod;
	ntt(c,-1,n);ll t=inv(n);
	for(int i=0;i<=len;++i)a[i]=c[i]*t%mod;
	return;
}

/*

1101011011110
0111101011101

*/

int main()
{
	pre();
	scanf("%s%s",a1+1,b1+1);
	int len=strlen(a1+1);
	for(int i=1;i<=len;++i)
	if(b1[i]=='1'&&a1[i]=='1')x++;
	else if(a1[i]=='1')y++;
	a[0]=1;
	for(int i=0;i<=x;++i)b[i]=rev[i+1];
	for(int t=y;t;t>>=1)
	{
		for(int i=x+1;i<N;++i)a[i]=b[i]=c[i]=d[i]=0;
		if(t&1)NTT(a,b,x,0);
		NTT(b,b,x,1);
	}
	ll ans=0;
	for(int i=0;i<=x;++i)(ans+=a[i]*fac[x]%mod*fac[y]%mod*fac[x+y])%=mod;
	cout<<ans;
}