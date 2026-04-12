#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
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
template<class T> inline void gmin(T &x,const T &y){x=x>y?y:x;}
template<class T> inline void gmax(T &x,const T &y){x=x<y?y:x;}
template<class T> inline bool Gmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T> inline bool Gmax(T &x,const T &y){return x<y?x=y,1:0;}
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
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
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
	const int N=1<<18,rt=3;
	const ull MAXMOD=(ull)mod*mod;
	int w[N],a[N],b[N];
	inline void fft(int *x,int n,int p){
		if(p) reverse(w+1,w+n);
		static ull a[N];
		for(int i=0,j=0;i<n;i++){
			if(i<j) swap(x[i],x[j]);
			for(int k=n>>1;(j^=k)<k;k>>=1);
		}
		for(int i=0;i<n;i++) a[i]=x[i];
		for(int i=2,CCNT=0;i<=n;i<<=1){
			int c=i>>1,now=n/i;
			CCNT++;
			for(int j=0;j<n;j+=i)
				for(int k=0,tn=0;k<c;k++,tn+=now){
					ull t=a[j+k+c]%mod*w[tn];
					a[j+k+c]=a[j+k]+MAXMOD-t;
					a[j+k]+=t;
				}
		}
		for(int i=0;i<n;i++)
			x[i]=a[i]%mod;
		if(p){
			for(int i=0,inv=exp(n,mod-2);i<n;i++)
				x[i]=(ll)x[i]*inv%mod;
			reverse(w+1,w+n);
		}
	}
	inline void mul(int *x,int *y,int n,int m,int *res,int k){
		for(int i=0;i<=n;i++) assert(x[i]>=0&&x[i]<mod);
		for(int i=0;i<=m;i++) assert(y[i]>=0&&y[i]<mod);
		int maxx=1;
		while(maxx<=(n+m)) maxx<<=1;
		int wn=exp(rt,(mod-1)/maxx);w[0]=1;
		for(int i=1;i<=maxx;i++) w[i]=(ll)w[i-1]*wn%mod;
		for(int i=0;i<maxx;i++) a[i]=b[i]=0;
		for(int i=0;i<=n;i++) a[i]=x[i];
		for(int j=0;j<=m;j++) b[j]=y[j];
		fft(a,maxx,0);fft(b,maxx,0);
		for(int i=0;i<maxx;i++) a[i]=(ll)a[i]*b[i]%mod;
		fft(a,maxx,1);
		for(int i=0;i<=k;i++) res[i]=(i<=n+m?a[i]:0);
	}
}
int n,m,fac[N],ifac[N],dp[2][N],b[N];

inline int C(int x,int y){
	return (ll)fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	scanf("%d%d",&n,&m);fac[0]=1;
	for(int i=1;i<=10000;i++)
		fac[i]=(ll)fac[i-1]*i%mod;
	ifac[10000]=exp(fac[10000],mod-2);
	for(int i=10000;i;i--)
		ifac[i-1]=(ll)ifac[i]*i%mod;
	dp[0][0]=1;
	for(int q=1;q<=n;q++)
		b[q]=ifac[q+2];
	for(int i=1;i<=m;i++){
		clr(dp[i&1],0);
		for(int p=0;p<=n;p++)
			dp[i-1&1][p]=(ll)dp[i-1&1][p]*ifac[p]%mod;
		NTT::mul(dp[i-1&1],b,n,n,dp[i&1],n);
		for(int p=0;p<=n;p++)
			dp[i&1][p]=(ll)dp[i&1][p]*fac[p+2]%mod;
		for(int p=0;p<=n;p++){
			int tmp=(ll)dp[i-1&1][p]*fac[p]%mod;
			if(p) ch(dp[i&1][p],(ll)tmp*(C(p+1,2)+1)); else ch(dp[i&1][p],tmp);
		}
/*		for(int p=0;p<=n;p++){
			int tmp=dp[i-1&1][p];
			if(!tmp) continue;
			if(p) ch(dp[i&1][p],(ll)tmp*(C(p+1,2)+1)); else ch(dp[i&1][p],tmp);
			for(int q=1;p+q<=n;q++)
				ch(dp[i&1][p+q],(ll)tmp*fac[p+q+2]%mod*ifac[q+2]%mod*ifac[p]);
		}*/
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ch(ans,(ll)dp[m&1][i]*C(n,i));
	printf("%d\n",ans);
	return 0;
}