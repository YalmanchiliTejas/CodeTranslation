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
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 83333,mo=998244353;
int n,a,b,fac[N],ifac[N];char s[N],t[N];
int g[N],f[N],w[N],x[N],y[N];
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;}
inline void fft(int *a, int n, int tp) {
	for (int i=1,j=0; i<n; i++) {
		for (int k=n>>1; !((j^=k)&k); k>>=1);
		if (i<j) swap(a[i],a[j]);
	}
	for (int j=2; j<=n; j<<=1) {
		w[0]=1; w[1]=power(3,(mo-1)/j); w[1]=tp==1?w[1]:inv(w[1]); int m=(j>>1)-1; //mo-1
		rep(i,2,m) w[i]=1LL*w[i-1]*w[1]%mo;
		for (register int i=0; i<n; i+=j) rep(k,0,m) {
			int x=1LL*a[i+k+(j>>1)]*w[k]%mo;
			a[i+k+(j>>1)]=a[i+k]-x>=0?a[i+k]-x:a[i+k]-x+mo;
			a[i+k]=a[i+k]+x<mo?a[i+k]+x:a[i+k]+x-mo;
		}
	}
}
inline void mul(int *_a, int *_b, int n1, int n2, int *c){
	static int a[N],b[N];int n;for(n=1;n<=n1+n2-2;n<<=1);
	rep(i,0,n1-1)a[i]=_a[i];rep(i,n1,n-1)a[i]=0;//WA!
	rep(i,0,n2-1)b[i]=_b[i];rep(i,n2,n-1)b[i]=0;
	fft(a,n,1);fft(b,n,1);rep(i,0,n-1)a[i]=1LL*a[i]*b[i]%mo;
	int ni=inv(n);fft(a,n,-1);rep(i,0,n-1)c[i]=1LL*a[i]*ni%mo;
}
inline void getinv(int *a, int n, int *_b){
	static int b[N];
	rep(i,0,n)b[i]=0;b[0]=inv(a[0]);
	for(int nn=1;nn<n;nn<<=1){//[0,nn)-->[0,2nn)
		static int c[N],d[N];int sz=4*nn;
		rep(i,0,nn-1)c[i]=b[i];rep(i,nn,sz-1)c[i]=0;
		rep(i,0,2*nn-1)d[i]=a[i];rep(i,2*nn,sz-1)d[i]=0;
		fft(c,sz,1);fft(d,sz,1);
		rep(i,0,sz-1)c[i]=1LL*c[i]*c[i]%mo*d[i]%mo;
		fft(c,sz,-1);int ni=inv(sz);rep(i,0,sz-1)c[i]=1LL*c[i]*ni%mo;
		rep(i,0,2*nn-1)b[i]=((2LL*b[i]-c[i])%mo+mo)%mo;
	}
	rep(i,0,n-1)_b[i]=b[i];
}
inline void qiudao(int *a, int n, int *b){//a[0..n-1]
	rep(i,1,n-1)b[i-1]=1LL*a[i]*i%mo;b[n-1]=0;
}
inline void jifen(int *a, int n, int *b){
	b[0]=0;rep(i,0,n-1)b[i+1]=1LL*a[i]*inv(i+1)%mo;
}
inline void getln(int *a, int n, int *b){//a[0..n-1]
	static int c[N];qiudao(a,n,c);
	static int d[N];getinv(a,n,d);
	static int e[N];mul(c,d,n,n,e);
	jifen(e,n,b);
}
inline void getexp(int *a, int n, int *_b){
	static int b[N];
	rep(i,0,n)b[i]=0;b[0]=1;
	for(int nn=1;nn<n;nn<<=1){//b[0..nn-1]-->b[0..2*nn-1]
		static int c[N];
		rep(i,nn,2*nn-1)b[i]=0;getln(b,nn*2,c);//×¢Òâ£¬¶Ôb[0..nn-1]ÇólnÓ¦¸ÃÊÇ%x^(2nn)ÒâÒåµÄ 
		rep(i,0,2*nn-1)c[i]=(a[i]-c[i]+mo)%mo;c[0]++;
		mul(b,c,nn,nn*2,b);
	}
	rep(i,0,n)_b[i]=b[i];
}
inline void polypower(int *_a, int n, int k, int *_b){//b[0..n-1]
	int c,d=0;while(!_a[d])d++;c=_a[d];int ni=inv(c);
	static int a[N];rep(i,0,n)a[i]=0;
	rep(i,d,n-1)a[i-d]=1LL*_a[i]*ni%mo;
	static int b[N];getln(a,n,b);
	rep(i,0,n-1)b[i]=1LL*b[i]*k%mo;
	getexp(b,n,b);
	rep(i,0,n)_b[i]=0;
	int mi=power(c,k);rep(i,0,n-d*k)_b[i+d*k]=1LL*mi*b[i]%mo;
}
int main() {
	scanf("%s%s",s+1,t+1);n=strlen(s+1);
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	rep(i,1,n)a+=s[i]=='1'&&t[i]=='0',b+=s[i]=='1'&&t[i]=='1';
	/*f[0][0]=1;
	rep(i,1,a)rep(j,0,b)rep(k,0,j)
		f[i][j]=(f[i][j]+1LL*f[i-1][k]*fac[b-k]%mo*ifac[b-j]%mo*ifac[j-k+1])%mo;*/
	static int q[N];rep(i,0,b)q[i]=ifac[i+1];
	polypower(q,b+1,a,g);//(ifac[i+1]*x^i)^a
	
	
	rep(i,0,b)g[i]=1LL*g[i]*fac[b]%mo*ifac[b-i]%mo;
	
	ll res=0;rep(j,0,b)res+=1LL*g[j]*fac[b-j]%mo;res=res%mo*fac[a+b]%mo*fac[a]%mo;cout<<res;
	return 0;
}
