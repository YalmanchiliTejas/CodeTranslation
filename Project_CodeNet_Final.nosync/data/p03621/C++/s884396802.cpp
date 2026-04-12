#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=10007,P=998244353;

inline int pow(int a,int b)
{
	int r=1;
	for(;b;b>>=1,a=(ll)a*a%P)
		if(b&1)r=(ll)r*a%P;
	return r;
}

namespace fft
{
	const int Pk=23,N=(1<<18)+5;
	
	uint id[N],tx[N],mt[N],nf[N],pw[100];

	inline void init_id(int y)
	{
		fo0(i,1<<y)id[i]=id[i>>1]>>1|(i&1)<<y-1;
	}
	
	#define idft(a,b) dft(a,b,1)
	
	inline void dft(int*s,int n,bool II=0)
	{
		fo0(i,1<<n)tx[i]=s[id[i]];
		fo(p,1,n)
		{
			int tm=pw[Pk-p],tmp=1;
			if(II)fd0(i,1<<p)mt[i]=tmp=(ll)tmp*tm%P;else fo0(i,1<<p)mt[i]=tmp,tmp=(ll)tmp*tm%P;
			int X,Y;
			for(int i=0,ie=1<<p,ir=ie/2,pp=ir-1;i<(1<<n);i+=ie)fo0(j,ir)
			{
				X=tx[i|j],Y=(ll)tx[i|j|ir]*mt[j]%P;
				tx[i|j]=(X+Y)%P,tx[i|j|ir]=(X-Y+P)%P;
			}
		}
		fo0(i,1<<n)s[i]=tx[i];
	}
	
	inline void init()
	{
		pw[0]=15311432;
		fo0(i,Pk)pw[i+1]=(ll)pw[i]*pw[i]%P;
	}
	
	inline void mul(int*a,int*b,int al,int bl)
	{
		static int sa[N],sb[N];
		int y=0;
		for(;(1<<y)<al+bl+5;y++);y++;
		fo0(i,al)sa[i]=a[i];
		fo(i,al,(1<<y)-1)sa[i]=0;
		fo0(i,bl)sb[i]=b[i];
		fo(i,bl,(1<<y)-1)sb[i]=0;
		init_id(y);
		dft(sa,y);
		dft(sb,y);
		fo0(i,1<<y)sa[i]=(ll)sa[i]*sb[i]%P;
		idft(sa,y);
		int t=pow(1<<y,P-2);
		fo0(i,al+bl-1)a[i]=(ll)sa[i]*t%P;
	}
}

char sa[N],sb[N];
int n,m,e,fac[N],fin[N],a[N*2],b[N*2];

int main()
{
	fft::init();
	fac[0]=1;
	fo1(i,N-1)fac[i]=(ll)fac[i-1]*i%P;
	fin[N-1]=pow(fac[N-1],P-2);
	fd1(i,N-1)fin[i-1]=(ll)fin[i]*i%P;
	in,sa,sb;
	n=strlen(sa);
	fo0(i,n)sa[i]-=48,sb[i]-=48,m+=sa[i]&&sb[i],e+=sa[i]&&!sb[i];
	//out,m,' ',e,'\n';
	fo(i,0,m)a[i]=fin[i+1];
	b[0]=1;
	for(int v=e;v;v>>=1)
	{
		if(v&1)fft::mul(b,a,m+1,m+1);
		if(v>>1)fft::mul(a,a,m+1,m+1);
	}
	//fo(i,0,m)out,a[i],' ';out,'\n';
	//fo(i,0,m)out,b[i],' ';out,'\n';
	int ans=0;
	fo(i,0,m)(ans+=b[i])%=P;
	ans=(ll)ans*fac[m]%P*fac[e]%P*fac[m+e]%P;
	out,ans,'\n';
}