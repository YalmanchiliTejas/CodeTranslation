#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld long double
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		(x)*(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("~%d~\n",x)
#define pp(x,y)		printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)	printf("~~~%d %d %d~~~\n",x,y,z)
#define f_in(x)		freopen(x".in","r",stdin)
#define f_out(x) 	freopen(x".out","w",stdout)
#define open(x)		f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 1
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
ll q[100000][3],a[310][310],mark[310][310],all_sz,A,B,top;
int main(){
	A=read(),B=read();
	For(i,1,A)For(j,1,B)a[i][j]=read();
	For(i,1,A)For(j,1,B)if (a[i][j]<a[i-1][j]||a[i][j]<a[i][j-1])	return puts("Impossible"),0;all_sz=202;
	For(cho_a,0,100)For(cho_b,0,100)For(cho_z,0,100)if (cho_a+cho_b+cho_z<=100){
		bool fl=1;
		For(i,1,A)For(j,1,B)if (a[i][j]>cho_a*i+cho_b*j+cho_z)	fl=0;
		if (!fl)	continue;
		fl=0;
		For(i,1,A)For(j,1,B)if (!mark[i][j]&&(a[i][j]==cho_a*i+cho_b*j+cho_z))	mark[i][j]=1,fl=1;
		if (fl){
			q[++top][0]=cho_a+1;
			q[top][1]=all_sz-cho_b;
			q[top][2]=cho_z;
		}
		break;
	}
	For(i,1,A)For(j,1,B)if (!mark[i][j])	return puts("Impossible"),0;
	ll node=1;
	For(i,1,100)	q[++top][0]=node,q[top][1]=++node,q[top][2]=-1;
	q[++top][0]=node;	q[top][1]=all_sz;	q[top][2]=-1;
	For(i,1,100)	q[++top][0]=(i==1)?1:node,q[top][1]=++node,q[top][2]=-2;
	q[++top][0]=node;	q[top][1]=all_sz;	q[top][2]=-2;
	puts("Possible");
	printf("%d %d\n",all_sz,top);
	For(i,1,top){
		if (q[i][2]>=0)	printf("%d %d %d\n",q[i][0],q[i][1],q[i][2]);
		if (q[i][2]==-1)printf("%d %d X\n",q[i][0],q[i][1]);
		if (q[i][2]==-2)printf("%d %d Y\n",q[i][0],q[i][1]);
	}printf("%d %d\n",1,all_sz);
}