#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vi poly;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int mod=998244353;
const int N=(1<<14)+5,G=3;
inline int power(int x,int p){
	int res=1;
	for(;p;x=1ll*x*x%mod,p>>=1)
		if(p&1)res=1ll*res*x%mod;
	return res;
}
inline const int fix(const int x){
	return x>=mod?x-mod:x;
}
void dft(int *A,int n){
	static ull W[N<<1],*H[30],*las=W,mx=0;
	for(;mx<n;mx++){
		H[mx]=las;ull w=1,wn=power(G,(mod-1)>>(mx+1));
		REP(i,1<<mx)*las++=w,w=w*wn%mod;
	}
	static ull a[N];
	for(int i=0,j=0;i<(1<<n);++i){
		a[i]=A[j];
		for(int k=1<<(n-1);(j^=k)<k;k>>=1);
	}
	ull tmp,*l=a,*r=a+1;
	for(int i=0;i<(1<<n);i+=2,++l,++r)
		tmp=*r,*r=*l+mod-tmp,*l+=tmp,++l,++r;
	for(int k=1,d=2;k<n;k++,d<<=1)
		for(int i=0;i<(1<<n);i+=d<<1){
			ull *l=a+i,*r=a+i+d,*w=H[k],t;
			for(int j=0;j<d;j+=2,l+=2,r+=2){
				t=(*w++)*(*r)%mod;
				*r=*l+mod-t,*l+=t;
				t=(*w++)*(*(r+1))%mod;
				*(r+1)=*(l+1)+mod-t,*(l+1)+=t;
			}
		}
	REP(i,1<<n)A[i]=a[i]%mod;
}
void idft(int *a,int n){
	reverse(a+1,a+(1<<n));
	dft(a,n);ll inv=power(1<<n,mod-2);
	REP(i,1<<n)a[i]=1ll*a[i]*inv%mod;
}

int fac[N],rev[N],f[N],g[N];
int n,m,k;

void init(int n){
	fac[0]=1;
	rep(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=power(fac[n],mod-2);
	per(i,n,1)rev[i-1]=(ll)rev[i]*i%mod;
}

int A[N],B[N];

int main(){
	read(m),read(n),init(m+2);
	rep(i,0,m)f[i]=(ll)fac[m]*rev[i]%mod*rev[m-i]%mod;
	while((1<<k)<2*m)k++;
	rep(j,1,m)B[m-j]=rev[j+2];
	dft(B,k);
	per(i,n,1){
		rep(j,1,m)A[j]=(ll)fac[j+2]*f[j]%mod;
		rep(j,m+1,(1<<k)-1)A[j]=0;
		dft(A,k);
		REP(j,1<<k)A[j]=(ll)A[j]*B[j]%mod;
		idft(A,k);
		rep(j,0,m)g[j]=((ll)A[m+j]*rev[j]+((ll)j*(j+1)/2+1)%mod*f[j])%mod;
		swap(f,g);
	}
	printf("%d\n",f[0]);
	return 0;
}