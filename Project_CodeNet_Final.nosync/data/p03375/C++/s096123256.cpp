#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
const int N=3005;
int mod,phi;
namespace{
	int fac[N],rev[N],s[N][N];
	int power(int x,int p,int mo){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mo)
			if(p&1)res=(ll)res*x%mo;
		return res;
	}
	int mul(int x,int y){
		return static_cast<ll>(x)*y%mod;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int C(int n,int m){
		return m<0||m>n?0:mul(fac[n],mul(rev[m],rev[n-m]));
	}
	void init(){
		const int lim=3000;
		fac[0]=1;
		rep(i,1,lim)fac[i]=(ll)fac[i-1]*i%mod;
		rev[lim]=power(fac[lim],mod-2,mod);
		per(i,lim,1)rev[i-1]=(ll)rev[i]*i%mod;
		rep(i,0,lim)s[i][0]=1;
		rep(i,1,lim)rep(j,1,i)
			s[i][j]=fix(s[i-1][j-1]+mul(s[i-1][j],j+1));
	}
}
int n,ans;

int main(){
	read(n),read(mod),init();
	rep(i,0,n){
		int tot=power(2,power(2,n-i,mod-1),mod);
		int t=power(2,n-i,mod),coef=mul((i&1?mod-1:1),C(n,i));
		rep(j,0,i){
			add(ans,mul(coef,mul(tot,s[i][j])));
			tot=mul(tot,t);
		}
	}
	cout<<ans<<endl;
	return 0;
}