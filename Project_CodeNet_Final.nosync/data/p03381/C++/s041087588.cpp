#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#define ll long long
#define inf 23333333
#define fur(i,x,y) for(i=x;i<=y;i++)
#define fdr(i,x,y) for(i=x;i>=y;i--)
#define Fur(i,x,y) for(ll i=x;i<=y;i++)
#define Fdr(x,y) for(ll i=x;i>=y;i--)
#define fl(i,x) for(ll i=head[x],to;to=e[i].to,i;i=e[i].next)
#define in2(x,y) in(x);in(y)
#define in3(x,y,z) in2(x,y);in(z)
#define in4(a,b,c,d) in2(a,b);in2(c,d)
#define clr(x,y) memset(x,y,sizeof(x))
#define cpy(x,y) memcpy(x,y,sizeof(x))

using namespace std;
/*---------------------------------------*/
namespace fib{char b[300000]= {},*f=b;}
#define gc ((*fib::f)?(*(fib ::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
inline void in(ll &x){x=0;char c;bool f=0;while((c=gc)>'9'||c<'0')if(c=='-')f=!f;x=c-48;while((c=gc)<='9'&&c>='0')x=x*10+c-48;if(f)x=-x;}
namespace fob{char b[300000]= {},*f=b,*g=b+300000-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce{~foce(){pob;fflush(stdout);}} _foce;
namespace ib{char b[100];}
inline void out(ll x){if(x==0){pc(48);return;}if(x<0){pc('-');x=-x;}char *s=ib::b;while(x) *(++s)=x%10,x/=10;while(s!=ib::b) pc((*(s--))+48);}
inline void outn(ll x){out(x);pc('\n');}
inline void swap(ll &x,ll &y){ll t=x;x=y;y=t;}
inline ll jdz(ll x){return x>0?x:-x;}
inline ll max(ll x,ll y){return x>y?x:y;}
inline ll min(ll x,ll y){return x<y?x:y;}
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
#define N 200001
ll a[N],b[N],n;
map<ll,ll> v;
int main(){
	in(n);
	Fur(i,1,n){in(a[i]);b[i]=a[i];}
	sort(a+1,a+n+1);ll m=(n+1)/2;
	Fur(i,1,n)v[a[i]]=i;
	Fur(i,1,n){
		if(v[b[i]]<=m)outn(a[m+1]);else outn(a[m]);
	}
}