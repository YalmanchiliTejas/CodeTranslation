#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 400010;
const int mod = 998244353,g = 3;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int x,y,k;

char sa[maxn],sb[maxn];

int fac[maxn];

int f[maxn],Ans[maxn];

int A[maxn],B[maxn];

void NTT(int *a,int f,int k){
	for(int i=0,j=0;i<k;i++){
		if(i>j)swap(a[i],a[j]);
		for(int l=k>>1;(j^=l)<l;l>>=1);
	}
	
	for(int i=1;i<k;i<<=1){int w=fexp(g,(f*(mod-1)/(i<<1)+mod-1)%(mod-1));
		for(int j=0;j<k;j+=i<<1){int e=1;
			for(int k=0;k<i;k++,e=1LL*e*w%mod){int x,y;
				x=a[j+k];y=1LL*a[j+k+i]*e%mod;
				a[j+k]=(x+y)%mod;a[j+k+i]=(x-y+mod)%mod;
			}
		}
	}
	
	if(f==-1){
		int _inv=fexp(k,mod-2);
		for(int i=0;i<k;i++)a[i]=1LL*a[i]*_inv%mod;
	}
}


void Conv(int *a,int *b,int *c){
	for(int i=0;i<k;i++)A[i]=B[i]=0;
	REP(i,0,x)A[i]=a[i],B[i]=b[i];
	NTT(A,1,k);NTT(B,1,k);
	REP(i,0,k-1)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,k);
	REP(i,0,x)c[i]=A[i];
}

void Work(){
//	cout<<x<<' '<<y<<endl;
	REP(i,0,x)f[i]=fexp(fac[i+1],mod-2);
//	REP(i,0,x)cout<<f[i]<<' ';cout<<endl;
	Ans[0]=1;
	for(k=1;k<=x+x;k<<=1);
	int t=y;
	while(y){
		if(y&1)Conv(Ans,f,Ans);
		Conv(f,f,f);y>>=1;
	}
//	REP(i,0,x)cout<<Ans[i]<<' ';cout<<endl;
	int ans=0;
	REP(i,0,x)ans=(ans+Ans[i])%mod;
//	cout<<ans<<endl;
//	dbg(fac[2]);
	ans=1ll*ans*fac[x]%mod*fac[t]%mod*fac[x+t]%mod;
	iout(ans);
}

void Init(){
	scanf("%s%s",sa+1,sb+1);
	int l=strlen(sa+1);
	REP(i,1,l){
		if(sa[i]=='1'&&sb[i]=='1')x++;
		else if(sa[i]=='1')y++;
	}
	fac[0]=1;REP(i,1,l+2)fac[i]=1ll*fac[i-1]*i%mod;
}

int main(){
	Init();
	Work();
	return 0;
}
