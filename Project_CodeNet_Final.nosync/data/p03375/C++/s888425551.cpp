#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3333;
int n,mo,res,C[N][N],ni[N],f[N][N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n, int mo) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int main() {
	read(n);read(mo);rep(i,0,n){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	f[0][0]=1;
	rep(m,1,n)rep(i,0,m)f[m][i]=((i-1>=0?f[m-1][i-1]:0)+1LL*f[m-1][i]*(i+1))%mo;
	rep(m,0,n){
		int ans=0,xs=power(2,n-m,mo);static int a[N];
		a[0]=1;rep(i,1,n)a[i]=1LL*a[i-1]*xs%mo;
		rep(i,0,m)ans=(ans+1LL*f[m][i]*a[i])%mo;ans=1LL*ans*power(2,power(2,n-m,mo-1),mo)%mo;
	//	cerr<<m<<' '<<ans<<endl;
		res=(res+1LL*ans*C[n][m]*(m&1?-1:1))%mo;
	}
	cout<<(res+mo)%mo;
	return 0;
}
