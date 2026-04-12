#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    (x=(x)*(y)%mod)
#define Mul1(x,y)   (x=(x)*(y)%mod1)
#define Add(x,y)    (x=(x+(y))%mod)
#define Add1(x,y)	(x=(x+(y))%mod1)
#define E(x)        return writeln(x),0
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(x,y,z,a)  printf("~~~%d %d %d %d~~~\n",x,y,z,a)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }
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
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
const ll N=110,mod=1e9+7;
ll n,a[N],h[N],f[N][N][2];
namespace GuYue{
	ll b[N],h[N],n;
	ll ppow(ll x,ll k){
		ll ans=1;
		for(;k;k>>=1,Mul(x,x))if (k&1)Mul(ans,x);
		return ans;
	}
	ll work(){
		memset(f,0,sizeof f);
		n=*a;
//		if (n==1)return ppow(2,a[1]);
		For(i,1,n)b[i]=a[i];
		sort(b+1,b+n+1);
		ll tot=unique(b+1,b+n+1)-b-1;b[tot+1]=b[tot];
		For(i,1,n)h[i]=lower_bound(b+1,b+tot+1,a[i])-b;
		f[0][0][0]=f[0][0][1]=1;
//		For(i,1,n)write(a[i]),putchar(' ');puts("");
		For(i,1,n){
			For(cur1,0,h[i-1])For(cur2,0,h[i])For(num1,0,1)For(num2,0,1)
			if (f[i-1][cur1][num1]){
				ll res1,res2,res3=0;
				if (cur2==h[i])res1=res2=1;
				else	res1=ppow(2,b[cur2+1]-b[cur2]-(cur2==0))-1,res2=ppow(2,a[i]-b[cur2+1]);
				if ((num1!=num2)&&(min(cur1,cur2)>=min(h[i-1],h[i]))){
					res3=1;
					if (i==1)res3=0;
				}
				Add(f[i][cur2][num2],f[i-1][cur1][num1]*res1%mod*res2%mod*res3);
				if (num1==num2){

					if (h[i]>=h[i-1]){
						if (cur2>=cur1&&cur1==h[i-1])
							Add(f[i][cur2][num2],f[i-1][cur1][num1]*res1%mod*res2);//writeln(f[i-1][cur1][num1]*res1*res2);
						lf (cur1==cur2)
							Add(f[i][cur2][num2],f[i-1][cur1][num1]*ppow(2,a[i]-a[i-1]));
					}else{
						if (cur2<=cur1&&cur2==h[i])
							Add(f[i][cur2][num2],f[i-1][cur1][num1]);
						lf (cur1==cur2)
							Add(f[i][cur2][num2],f[i-1][cur1][num1]);
					}				}
//				writeln(f[i-1][cur1][num1]*res1%mod*res2%mod*res3);
			}
		}ll ans=0;
		For(i,0,n)For(j,0,1)Add(ans,f[n][i][j]);
//		writeln(ans);
		return ans;
	}
}
int main(){
	n=read();
	For(i,1,n)h[i]=read();
	ll ans=1;h[n+1]=1;
	for(ll i=1;i<=n;)if (h[i]!=1){
		*a=0;
		for(;h[i]!=1;)a[++*a]=h[i++];
		Mul(ans,GuYue::work());
	}else	Mul(ans,2),++i;
	Add(ans,mod);
	writeln(ans);
}
/*
对于2
取反,相同。。。 
*/
