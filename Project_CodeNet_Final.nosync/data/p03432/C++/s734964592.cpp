#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=(1<<14)+5,mod=998244353;
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
namespace fft{
	int w[N],R[N];
	void init(int n){
		int d=0;
		while ((1<<d)<n)
			d++;
		assert((1<<d)==n);
		For(i,0,n-1)
			R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[0]=1,w[1]=Pow(3,(mod-1)/n);
		For(i,2,n-1)
			w[i]=(LL)w[i-1]*w[1]%mod;
	}
	void FFT(int *a,int n,int flag){
		For(i,0,n-1)
			if (i<R[i])
				swap(a[i],a[R[i]]);
		for (int d=1,t=n>>1;d<n;d<<=1,t>>=1)
			for (int i=0;i<n;i+=d<<1)
				for (int j=0;j<d;j++){
					int tmp=(LL)w[t*j]*a[i+j+d]%mod;
					a[i+j+d]=Del(a[i+j]-tmp);
					Add(a[i+j],tmp);
				}
		if (flag<0){
			int inv=Pow(n,mod-2);
			For(i,0,n-1)
				a[i]=(LL)a[i]*inv%mod;
			reverse(a+1,a+n);
		}
	}
}
using fft::FFT;
int n,m,len;
void Mul(int *A,int *B,int *C){
	static int a[N],b[N];
	For(i,0,len-1)
		a[i]=A[i],b[i]=B[i];
	fft::init(len);
	FFT(a,len,1),FFT(b,len,1);
	For(i,0,len-1)
		a[i]=(LL)a[i]*b[i]%mod;
	FFT(a,len,-1);
	For(i,0,len-1)
		C[i]=a[i];
}
int a[N],b[N],c[N];
int Fac[N],Inv[N];
void prework(){
	int n=N-1;
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	Fod(i,n,1)
		Inv[i-1]=(LL)Inv[i]*i%mod;
}
int C(int n,int m){
	if (m<0||m>n)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int main(){
	prework();
	n=read(),m=read();
	len=1;
	while (len<=n)
		len<<=1;
	len<<=1;
	//y[a+b] += x[a]*C(a+b+2,a)
	//y[a+b]/(a+b+2)! += x[a]/a! * (1/(b+2)!)
	a[0]=1;
	For(i,1,n)
		b[i]=Inv[i+2];
//	outarr(b,0,n);
	fft::init(len);
	FFT(b,len,1);
	while (m--){
		For(i,0,n)
			c[i]=a[i];
		FFT(a,len,1);
		For(i,0,len-1)
			a[i]=(LL)a[i]*b[i]%mod;
		FFT(a,len,-1);
		For(i,0,len-1)
			if (i>n)
				a[i]=0;
			else {
				a[i]=(LL)a[i]*(i+1)%mod*(i+2)%mod;
				Add(a[i],(LL)c[i]*(i*(i+1)/2+1)%mod);
			}
//		For(i,0,n)
//			printf("%lld ",(LL)a[i]*Fac[i]%mod);puts("");
	}
	int ans=0;
	For(i,0,n)
		Add(ans,(LL)a[i]*Fac[i]%mod*C(n,i)%mod);
	cout<<ans<<endl;
	return 0;
}