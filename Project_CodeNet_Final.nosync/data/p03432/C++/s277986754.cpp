/*=======================================
 * Author : ylsoi
 * Time : 2019.3.8
 * Problem : x
 * E-mail : ylsoi@foxmail.com
 * ====================================*/
#include<bits/stdc++.h>

#define REP(i,a,b) for(int i=a,i##_end_=b;i<=i##_end_;++i)
#define DREP(i,a,b) for(int i=a,i##_end_=b;i>=i##_end_;--i)
#define debug(x) cout<<#x<<"="<<x<<" "
#define fi first
#define se second
#define mk make_pair
#define pb push_back
typedef long long ll;

using namespace std;

void File(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
}

template<typename T>void read(T &_){
	_=0; T f=1; char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())_=(_<<1)+(_<<3)+(c^'0');
	_*=f;
}

string proc(){
	ifstream f("/proc/self/status");
	return string(istreambuf_iterator<char>(f),istreambuf_iterator<char>());
}

const int mod=998244353;
int id,n,m,ans;

namespace BIT{
	const int maxn=1e5+10;
	int sum[maxn];
	int lowbit(int x){return x&(-x);}
	void add(int p,int x,int rg){
		for(;p<=rg;p+=lowbit(p))sum[p]+=x;
	}
	int query(int p){
		int ret=0;
		for(;p>=1;p-=lowbit(p))ret+=sum[p];
		return ret;
	}
}

namespace subtask1{
	const int maxn=1e5+10;
	using namespace BIT;
	int a[maxn],b[maxn];
	vector<int>pos[maxn];
	void work(){
		REP(i,1,n)read(a[i]),pos[a[i]].pb(i);
		REP(i,1,m)read(b[i]);
		ans=1;
		REP(i,1,m){
			if(b[i]==n+1)continue;
			int lim=b[i];
			for(int p:pos[i])lim=p,add(p,1,n);
			ans=1ll*ans*(query(n)-query(lim-1))%mod;
		}
		printf("%d\n",ans);
	}
}

namespace subtask2{
	const int maxn=1e5+10;
	using namespace BIT;
	int a[maxn];
	vector<int>pos[maxn];
	void work(){
		REP(i,1,n)read(a[i]),pos[a[i]].pb(i);
		ans=1;
		REP(i,1,m){
			int l=n,r=1;
			for(int p:pos[i])l=min(l,p),r=max(r,p);
			if(l>r)ans=(1ll*query(n)*(query(n)+1)/2+1)%mod*ans%mod;
			else ans=1ll*ans*(query(l)+1)%mod*(query(n)-query(r-1)+1)%mod;
			for(int p:pos[i])add(p,1,n);
		}
		printf("%d\n",ans);
	}
}

const int maxn=8e3+10;
const int maxm=200+10;

int qpow(int x,int y){
	int ret=1; x%=mod;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int f[maxm][maxn],a[maxn<<2],b[maxn<<2];
int fac[maxn],ifac[maxn];
int lim,cnt,g[maxn<<2],ig[maxn<<2],dn[maxn<<2];

void ntt(int *A,int ty){
	REP(i,0,lim-1)if(i<dn[i])swap(A[i],A[dn[i]]);
	for(int len=1;len<lim;len<<=1){
		int w=(ty==1 ? g[len<<1] : ig[len<<1]);
		for(int L=0;L<lim;L+=len<<1){
			int wk=1;
			REP(i,L,L+len-1){
				int u=A[i],v=1ll*A[i+len]*wk%mod;
				A[i]=(u+v)%mod;
				A[i+len]=(u-v)%mod;
				wk=1ll*wk*w%mod;
			}
		}
	}
	if(ty==-1){
		int inv=qpow(lim,mod-2);
		REP(i,0,lim-1)A[i]=(1ll*A[i]*inv%mod+mod)%mod;
	}
}

void math_init(){
	fac[0]=1;
	REP(i,1,n+5)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n+5]=qpow(fac[n+5],mod-2);
	DREP(i,n+4,0)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;

	lim=1;
	while(lim<=(n<<1))lim<<=1,++cnt;
	g[lim]=qpow(3,(mod-1)/lim),ig[lim]=qpow(g[lim],mod-2);
	for(int i=lim>>1;i;i>>=1){
		g[i]=1ll*g[i<<1]*g[i<<1]%mod;
		ig[i]=1ll*ig[i<<1]*ig[i<<1]%mod;
	}

	if(!cnt)cnt=1;
	REP(i,0,lim)dn[i]=dn[i>>1]>>1|((i&1)<<(cnt-1));
}

void inc(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	else if(x<0)x+=mod;
}

int C(int x,int y){
	if(x<0 || y<0 || x<y)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

void work(){
	f[0][0]=1;
	REP(i,1,m){
		REP(j,0,lim-1){
			if(j<=n){
				a[j]=1ll*f[i-1][j]*ifac[j]%mod;
				b[j]=ifac[j+2];
			}
			else a[j]=b[j]=0;
		}
		ntt(a,1),ntt(b,1);
		REP(j,0,lim-1)a[j]=1ll*a[j]*b[j]%mod;
		ntt(a,-1);
		REP(j,0,n){
			f[i][j]=1ll*a[j]*fac[j+2]%mod;
			inc(f[i][j],-1ll*f[i-1][j]*C(j+2,2)%mod);
			inc(f[i][j],1ll*f[i-1][j]*(C(j+1,2)+1)%mod);
		}
	}
	REP(i,0,n)inc(ans,1ll*f[m][i]*C(n,i)%mod);
	printf("%d\n",ans);
}

int main(){
	//File();
	/*read(id),read(n),read(m);
	if(!id)subtask1::work(),exit(0);
	if(id==1)subtask2::work(),exit(0);*/
	read(n),read(m);
	math_init();
	work();
	return 0;
}
