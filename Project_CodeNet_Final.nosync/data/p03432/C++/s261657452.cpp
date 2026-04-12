#include <bits/stdc++.h>
#define For(i,x,y) for(int i=(x);i<=(y);++i)
#define Rof(i,x,y) for(int i=(x);i>=(y);--i)
#define FoR(i,x,y,z) for(int i=(x);i<=(y);i+=(z))
#define RoF(i,x,y,z) for(int i=(x);i>=(y);i-=(z))
#define Edge(x) for(int i=head[x],to=e[i].v;i;i=e[i].nxt,to=e[i].v)
typedef long long ll;
const int N=8005;
const int M=205;
const int mod=998244353;
using namespace std;

ll dp[M][N],g[N<<2],f[N<<2],fac[N],invf[N],G[N<<2][2],invl,ans=0;
int len,bit,rev[N<<2];

ll qpow(ll x,int y){ ll res=1; for(;y;y>>=1,(x*=x)%=mod) if(y&1) (res*=x)%=mod;return res; }
ll C(int x,int y){ return x>=y?fac[x]*invf[y]%mod*invf[x-y]%mod:0; }

void init(int n){
	fac[0]=fac[1]=invf[0]=invf[1]=1;
	For(i,2,n){
		fac[i]=1ll*fac[i-1]*i%mod;
		invf[i]=1ll*(1ll*mod-mod/i)*invf[mod%i]%mod;
	}
	For(i,2,n) (invf[i]*=invf[i-1])%=mod;
}

void FFT_init(int n){
	for(len=1,bit=0;len<=(n<<1)+2;len<<=1,++bit); invl=qpow(len,mod-2);
	For(i,0,len-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	G[len][1]=qpow(3ll,(mod-1)/len),G[len][0]=qpow(G[len][1],mod-2);
	for(int i=(len>>1);i>=1;i>>=1){
		G[i][1]=G[i<<1][1]*G[i<<1][1]%mod;
		G[i][0]=G[i<<1][0]*G[i<<1][0]%mod;
	}
}
void FFT(ll *a,int f){
	For(i,0,len-1) if(rev[i]>i) swap(a[i],a[rev[i]]);
	FoR(i,2,len,i){
		ll omega=G[i][f];int mid=i>>1;
		FoR(j,0,len-1,i){
			ll w=1;
			For(k,j,j+mid-1){
				ll u=a[k],v=a[k+mid]*w%mod;
				a[k]=(u+v)%mod,a[k+mid]=(u-v+mod)%mod;
				(w*=omega)%=mod;
			}
		} 
	}
	if(!f) For(i,0,len-1) (a[i]*=invl)%=mod;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	init(n+2);
	FFT_init(n);
	dp[0][0]=g[0]=1;
	FFT(g,1);
	For(j,1,m){
		dp[j][0]=1;
		For(i,0,len-1) f[i]=0;
		For(i,1,n) f[i]=invf[i+2];
		FFT(f,1);
		For(i,0,len-1) f[i]=f[i]*g[i]%mod;
		FFT(f,0);
		For(i,1,n) (dp[j][i]+=f[i])%=mod;
		For(i,1,n){
			(dp[j][i]*=fac[i+2])%=mod;
			(dp[j][i]+=(C(i+1,2)+1)%mod*dp[j-1][i])%=mod;
		}
		For(i,0,len-1) g[i]=0;
		For(i,0,n) g[i]=dp[j][i]*invf[i]%mod;
		FFT(g,1);
	}
	For(i,0,n) (ans+=dp[m][i]*C(n,i)%mod)%=mod;
	printf("%lld\n",ans);
}