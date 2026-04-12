#include<bits/stdc++.h>

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

const int N=16666,P=998244353;

struct Div{
	ull m,x;
	int s;
	Div(){}
	Div(ull mo):m(mo){
		s=__lg(mo-1);
		x=((__uint128_t(1)<<(s+64))+m-1)/m;
	}
	friend ull operator/(ull a,Div d){
		return ((__uint128_t(a)*d.x)>>d.s)>>64;
	}
	friend ull operator%(ull a,Div d){
		return a-a/d*d.m;
	}
};
const Div mod(P);

uint fpow(uint a,int t){
	uint r(1);
	for(;t;t>>=1,a=(ull)a*a%mod)if(t&1)r=(ull)r*a%mod;
	return r;
}

int n,m,k;
uint fac[N],ifac[N],inv[N],tx[N],ty[N],tz[N],dp[N],ret;
uint *ww[20],*iww[20],pol[N<<2],*pl=pol;
void init(int n){
	int i,p,l;uint w;
	for(l=2,p=0;l<=n;l<<=1,p++){
		ww[p]=pl;w=fpow(3,(P-1)/l);
		for(i=*pl=1;i<l>>1;i++)pl[i]=(ull)pl[i-1]*w%mod;pl+=l>>1;
		iww[p]=pl;w=fpow(w,P-2);
		for(i=*pl=1;i<l>>1;i++)pl[i]=(ull)pl[i-1]*w%mod;pl+=l>>1;
	}
}
void fft(uint a[],int n,int dft){
	int i,j,k,l,p;uint t,*w;
	for(i=1,j=n>>1;i<n-1;i++){
		if(i<j)swap(a[i],a[j]);
		for(k=n>>1;(j^=k)<k;k>>=1);
	}
	for(l=2,p=0;l<=n;l<<=1,p++){
		w=dft==1?ww[p]:iww[p];
		for(j=0,i=l>>1;j<n;j+=l)for(k=0;k<i;k++){
			uint&y=a[j+k];
			t=(ull)a[j+k+i]*w[k]%mod;
			(a[j+k+i]=y+P-t)<P?:a[j+k+i]-=P; 
			(y+=t)<P?:y-=P;
		}
	}
	if(dft==-1)for(i=0,t=fpow(n,P-2);i<n;i++)a[i]=(ull)a[i]*t%mod;
}

uint C(int n,int m){
	if(n<m)return 0;
	return (ull)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
 
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	fo(i,2,(n<<1)+2){
		fac[i]=(ull)fac[i-1]*i%mod;
		inv[i]=P-(ull)(P/i)*inv[P%i]%mod;
		ifac[i]=(ull)ifac[i-1]*inv[i]%mod;
	}
	dp[0]=1;
	for(k=1;k<=n<<1;k<<=1);
	init(k);
	fo(i,1,m){
		mms(tx,k);mms(ty,k);
		fo(j,0,n)tx[j]=(ull)dp[j]*ifac[j]%mod;
		fo(j,1,n)ty[j]=ifac[j+2];
		fft(tx,k,1);fft(ty,k,1);
		fo(j,0,k-1)tz[j]=(ull)tx[j]*ty[j]%mod;
		fft(tz,k,-1);
		fo(j,0,k-1)dp[j]=((ull)dp[j]*((j+1)*j/2+1)+(ull)tz[j]*fac[j+2])%mod;
	}
	fo(i,0,n)ret=(ret+(ll)dp[i]*C(n,i))%mod;
	printf("%u\n",ret);
	return 0;
}