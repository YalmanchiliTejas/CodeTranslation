#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1<<14|2,mod=998244353,G=3;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
struct ffter{
	int rev[N],n,L;
	int wn[N],WN[N];
	void zheng(poly &a){
		//for(auto &i:a)i=(i+mod)%mod;
	}
	void dft(poly &a){
		int n=a.size();
		for(int i=0;i<n;i++)if(rev[i]<i)swap(a[rev[i]],a[i]);
		zheng(a);
		for(int d=1,len=L-1;d<n;d<<=1,len--){
			for(int i=0;i<d;i++)WN[i]=wn[i<<len];
			for(int i=0;i<n;i+=d<<1){
				for(int j=0;j<d;j++){
					int t=(ll)WN[j]*a[i+j+d]%mod;
					a[i+j+d]=a[i+j]-t<0?a[i+j]-t+mod:a[i+j]-t;
					a[i+j]=a[i+j]+t>=mod?a[i+j]+t-mod:a[i+j]+t;
				}
			}
		}
	}
	void idft(poly &a){
		dft(a);
		reverse(a.begin()+1,a.end());
		int x=ksm(a.size(),mod-2);
		for(auto &i:a)i=(ll)i*x%mod;
	}
	void init(int N){
		n=1; L=0; while(n<N)n<<=1,L++;
		int w=ksm(G,(mod-1)/n);
		for(int i=0;i<n;i++){
			wn[i]=i?(ll)wn[i-1]*w%mod:1; rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
		}
	}
}T;

void FFT(poly &a,poly &b){
	int sz=a.size()+b.size()-1;
	T.init(sz);
	a.resize(T.n); b.resize(T.n);
	T.dft(a); T.dft(b);
	for(int i=0;i<T.n;i++)a[i]=(ll)a[i]*b[i]%mod;
	T.idft(a);
	a.resize(sz);
}
const int M=8005;
ll fac[M],ni[M],dp[M];
int main(){
	int n=read(),m=read();
	For(i,fac[0]=1,n+2)fac[i]=fac[i-1]*i%mod;
	ni[n+2]=ksm(fac[n+2],mod-2);
	Rep(i,n+2,1)ni[i-1]=ni[i]*i%mod;
	dp[0]=1;
	For(i,1,m){
		poly zs(n+1),jb(n+1);
		For(i,1,n)zs[i]=ni[i+2];
		For(i,0,n)jb[i]=dp[i]*ni[i]%mod;
		FFT(jb,zs);
		For(i,0,n)dp[i]=(dp[i]*(i*(i+1)/2+1)+jb[i]*fac[i+2])%mod;
	}
	ll ans=0;
	For(i,0,n)ans=(ans+fac[n]*ni[i]%mod*ni[n-i]%mod*dp[i])%mod;
	cout<<ans<<endl;
}