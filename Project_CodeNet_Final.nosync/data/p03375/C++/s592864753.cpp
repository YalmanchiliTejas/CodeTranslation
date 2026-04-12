#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f,oo = inf;
#define IL inline
#define RG register
#define rep(i,a,b) for(RG int i=(a);i<(b);++i)
#define Rep(i,a,b) for(RG int i=(a);i<=(b);++i)
#define Dep(i,a,b) for(RG int i=(a);i>=(b);--i)
#define pc putchar
#define gc getchar
IL ll read(){
    RG ll x=0;char f=0;RG char c=gc();
    for(;!isdigit(c);c=gc())f|=(c=='-');
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return f?-x:x;
}
IL double readdb(){
    RG double x=0,p=0.1;RG char f=0,c=gc();
    for(;!isdigit(c);c=gc())f|=(c=='-');
    for(;isdigit(c);c=gc())x=x*10+(c^48);
    if(c=='.')for(c=gc();isdigit(c);c=gc(),p/=10)x=x+(c^48)*p;
    return f?-x:x;
}
IL void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);pc(x%10+'0');}
IL void writeln(ll x){write(x);puts("");}
IL void writeln(ll x,char c,ll y){write(x);pc(c);writeln(y);}
IL void writeln(ll x,char c,ll y,char d,ll z){write(x);pc(c);write(y);pc(d);writeln(z);}
#define debug(x) printf(#x" = %d\n",x);
#define rd() read()
#define rdb() readdb()
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define firstn(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define int ll
#define hash __hash
#define union _union
const int maxn = 1000005;
ll S[3333][3333],C[3333][3333],n,Mod;
ll qpow(ll a,ll b,ll Mod){
	ll ans = 1;
	for(;b;b>>=1,a=1ll*a*a%Mod)
		if(b&1) ans = 1ll * ans * a % Mod;
	return ans;
}
ll w(int i){
	ll res = 0;
	ll tmp1 = 1,tmp2 = qpow(2,qpow(2,n-i,Mod-1),Mod) % Mod;
	ll t = qpow(2,n-i,Mod);
	for(int j=0;j<=i;j++){
		res = (res + S[i][j] * tmp1 % Mod * tmp2 % Mod) % Mod;
		tmp1 = tmp1 * t % Mod;
	}
	return res;
}
void init(){
	n = rd(),Mod = rd();
	C[0][0]=1;
	Rep(i,1,n){
		C[i][0] = 1;
		Rep(j,1,i){
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%Mod;
		}
	}
	S[0][0] = 1;
	Rep(i,1,n){
		S[i][0] = 1;
		Rep(j,1,i){
			S[i][j] = (S[i-1][j-1] + S[i-1][j] * (j+1) % Mod) %  Mod;
		}
	}
	ll ans = 0;
	Rep(i,0,n){
		if(i&1) ans =(ans + 1ll * (Mod-1) * C[n][i] % Mod * w(i) % Mod) % Mod; else
				ans =(ans + 1ll * 1       * C[n][i] % Mod * w(i) % Mod) % Mod;
	}
	writeln(ans);
	
}
signed main(){
	init();
	return 0;
}