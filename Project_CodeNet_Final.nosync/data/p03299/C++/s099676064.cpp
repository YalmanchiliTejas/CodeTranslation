#include<bits/stdc++.h>
using namespace std;
#define cs const
#define re register
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define y1 shinkle
#define fi first
#define se second
#define bg begin
namespace IO{

cs int RLEN=1<<20|1;
inline char gc(){
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob)&&(ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob)?EOF:*ib++;
}
inline int read(){
    char ch=gc();
    int res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res*10)+(ch^48),ch=gc();
    return f?res:-res;
}
inline ll readll(){
    char ch=gc();
    ll res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res*10)+(ch^48),ch=gc();
    return f?res:-res;
}
inline char readchar(){
	char ch=gc();
	while(isspace(ch))ch=gc();
	return ch;
}
inline int readstring(char *s){
	int top=0;char ch=gc();
	while(isspace(ch))ch=gc();
	while(!isspace(ch)&&ch!=EOF)s[++top]=ch,ch=gc();
	s[top+1]='\0';return top;
}

}
using IO::read;
using IO::readll;
using IO::readstring;
using IO::readchar; 
template<typename tp>inline void chemx(tp &a,tp b){(a<b)?(a=b):0;}
template<typename tp>inline void chemn(tp &a,tp b){(a>b)?(a=b):0;}
cs int mod=1e9+7;
inline int add(int a,int b){return (a+b)>=mod?(a+b-mod):(a+b);}
inline int dec(int a,int b){return (a<b)?(a-b+mod):(a-b);}
inline int mul(int a,int b){static ll r;r=(ll)a*b;return (r>=mod)?(r%mod):r;}
inline void Add(int &a,int b){a=(a+b)>=mod?(a+b-mod):(a+b);}
inline void Dec(int &a,int b){a=(a<b)?(a-b+mod):(a-b);}
inline void Mul(int &a,int b){static ll r;r=(ll)a*b;a=(r>=mod)?(r%mod):r;}
inline int ksm(int a,int b,int res=1){for(;b;b>>=1,Mul(a,a))(b&1)&&(Mul(res,a),1);return res;}
inline int Inv(int x){return ksm(x,mod-2);}
cs int N=105;
int n,cnt,f[N][N],a[N],h[N],c[N];
int main(){
	#ifdef Stargazer
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(int i=1;i<=n;i++)h[i]=c[i]=read();
	sort(c+1,c+n+1),cnt=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+cnt+1,h[i])-c;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		Add(f[i][0],mul(f[i-1][0],2));
		for(int j=a[i]+1;j<=a[i-1];j++)Add(f[i][0],mul(f[i-1][j],2));
		int d=ksm(2,max(0,h[i]-h[i-1]));
		for(int j=1;j<=min(a[i],a[i-1]);j++)Add(f[i][j],mul(f[i-1][j],d));
		if(i==1)Add(f[1][1],mul(f[0][0],mul(ksm(2,c[1])-2,ksm(2,h[i]-c[1]))));
		for(int j=max(2,a[i-1]+1);j<=a[i];j++)
		Add(f[i][j],mul(f[i-1][0],mul(ksm(2,c[j]-c[j-1])-1,mul(2,ksm(2,h[i]-c[j])))));
	}int res=0;
	for(int i=0;i<=a[n];i++)Add(res,f[n][i]);
	cout<<res<<'\n';return 0;
}