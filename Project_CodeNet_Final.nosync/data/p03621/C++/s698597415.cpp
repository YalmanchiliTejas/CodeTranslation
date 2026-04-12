#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1<<16,mod=998244353;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n,m,c,d;
void IN(){
	static char s[N];
	static int a[N],b[N];
	cin>>s+1;
	n=strlen(s+1);
	For(i,1,n)
		a[i]=s[i]-'0';
	cin>>s+1;
	For(i,1,n)
		b[i]=s[i]-'0';
	For(i,1,n)
		if (a[i]&&!b[i])
			c++;
		else if (a[i]&&b[i])
			d++;
}
namespace fft{
	int w[N],R[N];
	void init(int n){
		int d=0;
		while ((1<<d)<n)
			d++;
		w[0]=1,w[1]=Pow(3,(mod-1)>>d);
		For(i,2,n-1)
			w[i]=(LL)w[i-1]*w[1]%mod;
		For(i,0,n-1)
			R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
	}
	void FFT(int *a,int n,int flag){
		For(i,0,n-1)
			if (i<R[i])
				swap(a[i],a[R[i]]);
		for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
			for (int i=0;i<n;i+=d<<1)
				for (int j=0;j<d;j++){
					int tmp=(LL)w[t*j]*a[i+j+d]%mod;
					a[i+j+d]=Del(a[i+j]-tmp);
					Add(a[i+j],tmp);
				}
		if (flag<0){
			reverse(a+1,a+n);
			int inv=Pow(n,mod-2);
			For(i,0,n-1)
				a[i]=(LL)a[i]*inv%mod;
		}
	}
}
using fft::FFT;
int Fac[N],Inv[N],Iv[N];
void prework(){
	int n=N-1;
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	Fod(i,n,1)
		Inv[i-1]=(LL)Inv[i]*i%mod;
	For(i,1,n)
		Iv[i]=(LL)Inv[i]*Fac[i-1]%mod;
}
vi Fix(vi a,int n){
	a.resize(n,0);
	return a;
}
vi operator + (vi a,vi b){
	int n=max(a.size(),b.size());
	a=Fix(a,n),b=Fix(b,n);
	For(i,0,n-1)
		Add(a[i],b[i]);
	return a;
}
vi operator - (vi a,vi b){
	int n=max(a.size(),b.size());
	a=Fix(a,n),b=Fix(b,n);
	For(i,0,n-1)
		Del(a[i],b[i]);
	return a;
}
vi operator * (vi a,vi b){
	int n=1,m=a.size()+b.size()-1;
	while (n<a.size()+b.size())
		n<<=1;
	a=Fix(a,n),b=Fix(b,n);
	fft::init(n),FFT(&a[0],n,1),FFT(&b[0],n,1);
	For(i,0,n-1)
		a[i]=(LL)a[i]*b[i]%mod;
	FFT(&a[0],n,-1);
	return Fix(a,m);
}
vi Der(vi a){
	int n=(int)a.size()-1;
	For(i,0,n-1)
		a[i]=(LL)a[i+1]*(i+1)%mod;
	return Fix(a,n);
}
vi Int(vi a){
	int n=(int)a.size();
	a.pb(0);
	Fod(i,n,1)
		a[i]=(LL)a[i-1]*Iv[i]%mod;
	a[0]=0;
	return a;
}
vi inv(vi a){
	int n=a.size();
	if (n==1)
		return (vi){Pow(a[0],mod-2)};
	vi b=inv(Fix(a,(n+1)>>1));
	return Fix(b+b-a*b*b,n);
}
vi Ln(vi a){
	int n=a.size();
	return Int(Fix(Der(a)*inv(a),n-1));
}
vi Exp(vi a){
	int n=a.size();
	if (n==1)
		return (vi){1};
	vi b=Fix(Exp(Fix(a,(n+1)>>1)),n);
	return Fix(b*((vi){1}-Ln(b)+a),n);
}
vi Pow(vi a,int b){
	int n=a.size();
	a=Ln(a);
	For(i,0,n-1)
		a[i]=(LL)a[i]*b%mod;
	return Exp(a);
}
void Test(){
	int n=read();
	vi a(n);
	For(i,0,n-1)
		a[i]=read();
	vi b=a*a;
	outarr(b,0,b.size()-1);
	b=Der(a);
	outarr(b,0,b.size()-1);
	b=Int(a);
	outarr(b,0,b.size()-1);
	b=inv(a);
	outarr(b,0,b.size()-1);
	b=Ln(a);
	outarr(b,0,b.size()-1);
	b=Exp(a);
	outarr(b,0,b.size()-1);
}
int main(){
	prework();
//	Test();
	IN();
	n=d+1;
	vi tmp(n);
	vi x(n);
	For(i,1,n-1)
		x[i]=Iv[i];
	vi a=Exp(Fix(x,n));
	vi e=Exp(Fix((vi){0,1},n+1))-(vi){1};
	For(i,0,n-1)
		e[i]=e[i+1];
	e=Fix(e,n);
	vi b=Pow(e,c);
	a=Fix(a*b,n);
	int ans=(LL)a[d]*Fac[c]%mod*Fac[d]%mod*Fac[c+d]%mod;
	cout<<ans<<endl;
	return 0;
}