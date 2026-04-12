#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
const int MOD=998244353;
int K,w[2][SZ]; ll rv;
inline ll qp(ll a,ll b)
{
    ll ans=1; a%=MOD;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
inline void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    ll g=qp(3,(MOD-1)/K);
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g%MOD;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
    rv=qp(K,MOD-2);
}
inline void fft(int* x,int v)
{
    for(int i=0;i<K;i++) (x[i]<0)?(x[i]+=MOD):0;
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
        for(int l=0;l<i>>1;l++)
        {
            register int W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
            for(register int j=0;j<K;j+=i)
            {
                p[j]=(q[j]-(t=(ll)p[j]*W%MOD)<0)?(q[j]-t+MOD):(q[j]-t);
                q[j]=(q[j]>=MOD-t)?(q[j]-MOD+t):(q[j]+t);
            }
        }
    if(!v) return;
    for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
#define SZ 666666
int f[233][8888],a[16388],b[16388];
ll fac[SZ],rfac[SZ];
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i>=1;--i) rfac[i-1]=rfac[i]*i%MOD;
	fftinit(16000); f[0][0]=1;
	for(int j=1;j<=8003;++j) b[j]=rfac[j+2];
	fft(b,0);
	for(int i=1;i<=200;++i)
	{
		for(int k=0;k<K;++k) a[k]=0;
		for(int k=0;k<=8003;++k)
			a[k]=f[i-1][k]*(ll)rfac[k]%MOD;
		fft(a,0);
		for(int k=0;k<K;++k) a[k]=a[k]*(ll)b[k]%MOD;
		fft(a,1);
		for(int k=0;k<=8003;++k)
			f[i][k]=
			(f[i-1][k]*(ll)(((k+1)*(ll)k/2+1)%MOD)
			+a[k]*(ll)fac[k+2])%MOD;
	}
	int n,m;
	cin>>n>>m;
	ll ans=0;
	for(int i=0;i<=n;++i)
		ans+=f[m][i]*(ll)fac[n]%MOD*rfac[i]%MOD*rfac[n-i]%MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}
