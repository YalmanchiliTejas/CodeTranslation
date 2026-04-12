#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
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

const int maxn = 200010;
const int mod = 1e9+7;
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

int n;

ll ans=1e18;

PII A[maxn];

ll calc(int pos){
	int mx=max(A[1].fi,A[pos].fi),mn=min(A[pos].se,A[1].se);
	REP(i,2,n)if(i!=pos)mx=max(mx,A[i].fi),mn=min(mn,A[i].se);
	return 1LL*(mx-A[1].fi)*(A[pos].se-mn);
}

ll calc2(int pos){
	int ans=2e9;
	int mn=min(A[1].se,A[pos].fi),mx=max(max(A[1].se,A[pos].fi),A[n].fi);
	REP(i,2,n)if(i!=pos){
		ans=min(ans,mx-min(mn,A[i].fi));
		mn=min(mn,A[i].se);mx=max(mx,A[i].se);
	}
	ans=min(ans,mx-mn);
	return ans;
}

void Work(){
	int pos=1;
	REP(i,1,n)if(A[i].se>=A[pos].se)pos=i;
	ans=min(ans,calc(pos));
	//cout<<ans<<endl;
	if(pos!=1)ans=min(ans,calc2(pos)*(A[pos].se-A[1].fi));
	cout<<ans<<endl;
}

void Init(){
	read(n);
	REP(i,1,n)read(A[i].fi,A[i].se);
	REP(i,1,n)if(A[i].fi>A[i].se)swap(A[i].fi,A[i].se);
	sort(A+1,A+n+1);
}

int main(){
	Init();
	Work();
	return 0;
}
