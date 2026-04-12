#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
#define go(u) for (int o=ft[u],v;v=E[o].t;o=E[o].n)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef double dob;
typedef pair<int,int> par;
const int N=20010,lim=20000,P=998244353,g=3,ig=(P+1)/3;
int n,m;
LL s1[N],s2[N],inv[N];
LL C(int n,int m){
	if (m<0||m>n) return 0;
	return s1[n]*s2[m]%P*s2[n-m]%P;
}
LL pw(LL x,LL k){
	LL y=1;
	while (k){
		if (k&1) y=y*x%P;
		x=x*x%P;
		k>>=1;
	}
	return y;
}
namespace po{
	LL a[N],b[N],c[N];
	void dft(LL* a,int n,int op){
		static LL r[N];
		r[0]=0;
		for (int i=0;i<n;i+=2){
			r[i]=r[i>>1]>>1;
			r[i+1]=r[i]|n>>1;
		}
		for (int i=0;i<n;i++) if (i<r[i]) swap(a[i],a[r[i]]);	
		for (int h=2;h<=n;h<<=1){
			LL wn=pw(op==1?g:ig,(P-1)/h);
			for (int i=0;i<n;i+=h){
				LL w=1;
				for (int j=i;j<i+h/2;j++){
					LL x=a[j],y=a[j+h/2];
					a[j]=(x+y*w)%P;
					a[j+h/2]=(x-y*w)%P;
					w=w*wn%P;
				}
			}
		}
		if (op==-1) for (int i=0,iv=pw(n,P-2);i<n;i++) a[i]=a[i]*iv%P;
	}
	void mul(LL* _a,LL* _b,LL* _c,int len){
		memcpy(a,_a,len*8);
		memcpy(b,_b,len*8);
		dft(a,len,1),dft(b,len,1);
		rep(i,0,len-1) c[i]=a[i]*b[i]%P;
		dft(c,len,-1);
		memcpy(_c,c,len*8);
	}
};
struct poly{
	int l;
	vector <LL> a;
	LL& operator [](int k){return a[k];}
	void set(int len){
		while (a.size()<len) a.push_back(0);
		while (l>len) a[--l]=0;
		l=len;
	}
	void operator *=(poly k){
		int len=1;
		while (len<l+k.l-1) len<<=1;
		set(len),k.set(len);
		po::mul(&a[0],&k[0],&a[0],len);
	}
}p1,p2;
void init(){
	inv[1]=1;
	rep(i,2,lim) inv[i]=inv[P%i]*(P-P/i)%P;
	s1[0]=s2[0]=1;
	rep(i,1,lim){
		s1[i]=s1[i-1]*i%P;
		s2[i]=s2[i-1]*inv[i]%P;
	}
	p1.set(n+5),p1[0]=1;
	p2.set(n+5);
	rep(i,1,n) p2[i]=s2[i+2];
}
LL tp[N];
int main(){
	scanf("%d%d",&n,&m);
	init();
	while (m--){
		rep(i,0,n) tp[i]=p1[i];
		p1*=p2;
		p1.set(n+5);
		rep(i,0,n) p1[i]=p1[i]*(i+1)%P*(i+2)%P;
		rep(i,0,n) p1[i]=(p1[i]+tp[i]*((LL)i*(i+1)/2%P+1))%P;
	}
	rep(i,0,n) p1[i]=p1[i]*s1[i]%P;
	LL ans=0;
	rep(i,0,n) ans=(ans+p1[i]*C(n,i))%P;
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
	return 0;
}
