#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}

const int N = 18400;
int fac[N+10],invfac[N+10];

int C(int n,int m){
	if(n<0 || m<0 || m>n)return 0;
	return mul(fac[n],mul(invfac[m],invfac[n-m]));
}

int n,m,dp[303][8080],coef[N],co2;

struct poly{
	int wroot = 3;
	int n,l,rev[N],mrt[N],invn,MXLNTT = 14,MXNTT = 1<<MXLNTT;
	int uptopow(int x){
		while(x!=(x&(-x)))x+=x&(-x);
		return x;
	}
	void ori(){
		int stepv = mpow(wroot,(mod-1)/MXNTT);
		mrt[0] = 1;	for(int i=1;i<=MXNTT;i++)mrt[i] = mul(mrt[i-1],stepv);
		rev[0] = 0;	for(int i=1;i<=MXNTT;i++)rev[i] = (rev[i>>1]>>1)|(i&1?(1<<(MXLNTT-1)):0);
	}
	void dft(int a[],int sz,int typ){
		static int cc1[N],us[N];
		int mn = MXLNTT-__builtin_ctz(sz);
		for(int i=0;i<sz;i++)cc1[i] = a[rev[i]>>mn];
		for(int l=2;l<=sz;l*=2){
			int m = l>>1,step = MXNTT/l;
			if(typ == 0) for(int i=0,j = 0;i<=m;i++,j+=step)us[i] = mrt[j];
			else for(int i=0,j=MXNTT;i<=m;i++,j-=step)us[i] = mrt[j];
			for(int i = 0;i!=sz;i+=l){
				for(int j=0;j<m;j++){
					int t = mul(cc1[i+j+m],us[j]);
					cc1[i+j+m] = sub(cc1[i+j],t);
					cc1[i+j] = add(cc1[i+j],t);
				}
			}
		}
		if(typ){
			int invn = mpow(sz,mod-2);
			for(int i=0;i<sz;i++)a[i] = mul(cc1[i],invn);
		}else{
			memcpy(a,cc1,sz*sizeof(int));
		}
	}
}NTT;

int main() {
	fac[0] = 1;
	for(int i=1;i<=N;i++)fac[i] = mul(fac[i-1],i);
	invfac[N] = mpow(fac[N],mod-2);
	for(int i=N-1;i>=0;i--) invfac[i] = mul(invfac[i+1],i+1);
	NTT.ori();
	read(n);read(m);
	for(int i=0;i<=n;i++) dp[1][i] = 1;
	for(int i=1;i<=n;i++) coef[i] = invfac[i+2];
	int sz = NTT.uptopow((n+1)*2);
	NTT.dft(coef,sz,0);
	int pdp[N];
	int inv2 = (mod+1)/2;
	for(int ech=2;ech<=m;ech++){
		memset(pdp,0,sizeof(pdp));
		for(int i=0;i<=n;i++)pdp[i] = mul(dp[ech-1][i],invfac[i]);
		NTT.dft(pdp,sz,0);
		for(int i=0;i<sz;i++)pdp[i]=mul(pdp[i],coef[i]);
		NTT.dft(pdp,sz,1);
		for(int i=0;i<=n;i++){
			dp[ech][i] = add(mul(pdp[i],fac[i+2]),mul(dp[ech-1][i],i*(i+1)/2+1));
		}
	}
	int ans = 0;
	for(int i=0;i<=n;i++)ans = add(ans,mul(C(n,i),dp[m][i]));
	cout<<ans<<endl;
	return 0;
}
