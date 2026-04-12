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
const int N=305,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int A,B,S,T,d[15][15];
int f[105][105],ans[N];
bool vis[N],use[105][105];
vector<pii> g[N];

int X[N],Y[N];
vector<pair<pii,int> > edge;
inline void push(int x,int y,int k){
	edge.pb(mp(mp(x,y),k));
}
inline void putans(){
	puts("Possible");
	printf("%d %d\n",300,SZ(edge));
	for(auto i:edge){
		printf("%d %d ",i.FF.FF,i.FF.SS);
		if(i.SS>=0) printf("%d\n",i.SS); else if(i.SS==-1) puts("X"); else puts("Y");
	}
	printf("%d %d\n",S,T);
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	read(A,B);
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++){
			read(d[i][j]);
			for(int a=0;a<=100;a++)
				for(int b=0;b<=100;b++){
					int tmp=a*i+b*j;
					gmax(f[a][b],d[i][j]-tmp);
				}
		}
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++){
			bool isok=0;
			for(int a=0;a<=100;a++)
				for(int b=0;b<=100;b++)
					if(f[a][b]+a*i+b*j==d[i][j])
						isok=1,use[a][b]=1;
			if(!isok){puts("Impossible");return 0;}
		}
	S=233;T=234;
	X[0]=S;Y[0]=T;
	for(int i=1;i<=100;i++)
		X[i]=i;
	for(int i=1;i<=100;i++)
		Y[i]=i+105;
	for(int i=0;i<100;i++)
		push(X[i],X[i+1],-1);
	for(int i=0;i<100;i++)
		push(Y[i+1],Y[i],-2);
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			if(use[i][j]) push(X[i],Y[j],f[i][j]);
	putans();
	return 0;
}