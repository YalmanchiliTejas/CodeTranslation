#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=10005,M=100005,mod=998244353;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

namespace NTT{
	const int M=300005;
	int w[M],a[M],b[M];
	inline void fft(int *x,int n){
		for(int i=0,j=0;i<n;i++){
			if(i<j) swap(x[i],x[j]);
			for(int k=n>>1;(j^=k)<k;k>>=1);
		}
		for(int i=2;i<=n;i<<=1){
			int c=i>>1,now=n/i;
			for(int j=0;j<n;j+=i)
				for(int k=0;k<c;k++){
					int t=(ll)x[j+k+c]*w[now*k]%mod;
					x[j+k+c]=(x[j+k]-t)%mod;
					(x[j+k]+=t)%=mod;
				}
		}
	}
	inline void mul(int *x,int *y,int n,int *res){
		int maxx=1,wn;
		while(maxx<=(n*2)) maxx<<=1;
		for(int i=0;i<maxx;i++) a[i]=b[i]=0;
		for(int i=0;i<=n;i++) a[i]=x[i],b[i]=y[i];
		w[0]=1;wn=exp(3,(mod-1)/maxx);
		for(int i=1;i<=maxx;i++) w[i]=(ll)w[i-1]*wn%mod;
		fft(a,maxx);fft(b,maxx);
		for(int i=0;i<maxx;i++) a[i]=(ll)a[i]*b[i]%mod;
		reverse(w+1,w+maxx);
		fft(a,maxx);
		int inv=exp(maxx,mod-2);
		for(int i=0;i<=n;i++) res[i]=((ll)a[i]*inv%mod+mod)%mod;
	}
}


char a[N],b[N];
int n,m,K,dp[N],fac[N],ifac[N];

int C(int x,int y){
	return (ll)fac[x]*ifac[x-y]%mod*ifac[y]%mod;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	n=10001;
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=0;i<=n;i++) ifac[i]=exp(fac[i+1],mod-2);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int LEN=strlen(a+1);
	n=0;
	for(int i=1;i<=LEN;i++)
		if(a[i]=='1'){
			if(b[i]=='1') m++; else n++;
		}
	dprintf("%d %d\n",n,m);K=n+m;
	clr(dp,0);
	dp[0]=1;
	int t=n;
	while(t){
		if(t&1) NTT::mul(dp,ifac,m,dp);
		NTT::mul(ifac,ifac,m,ifac);t>>=1;
	}
	
/*	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=j;k++)
				ch(dp[i][j],(ll)dp[i-1][j-k]*ifac[k+1]);*/
	int ans=0;
	for(int j=0;j<=m;j++)
		ch(ans,dp[j]);
	ans=(ll)ans*fac[n]%mod*fac[m]%mod*fac[K]%mod;
	print(ans);
	return 0;
}