#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)
{
	T f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');
	x*=f;
	return x;
}
ll rd(){ll x;rd(x);return x;}
//inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;

const int N=200020;
ll a[N],_ls[N],rs[N];ll*ls=_ls+5;
int main()
{
	int n=rd();
	F(i,1,n) rd(a[i]);
	F(i,1,n) ls[i]=ls[i-2]+a[i];
	//F(i,1,n) cout<<ls[i]<<' ';cout<<endl;
	UF(i,n,1) rs[i]=rs[i+2]+a[i];
	//F(i,1,n) cout<<rs[i]<<' ';cout<<endl;
	ll ans=-300000000000000ll;
	F(i,0,n/2) ans=max(ans,ls[2*(n/2-i)-1]+rs[n-2*(i-1)]);
	//cout<<ans<<endl;
	if(n&1)
	{
		ll tmp=300000000000000ll;
		ll f=300000000000000ll;
		//F(i,0,n) cout<<ls[i]-ls[i-1]<<' ';cout<<endl;
		F(i,1,n)
		{
			if(i&1) {f=min(f,tmp+ls[i]-ls[i-1]);tmp=min(tmp,ls[i-1]-ls[i-2]);}
			//cout<<tmp<<' '<<f<<endl;
		}
		ans=max(ans,ls[n]-f);
	}
	cout<<ans<<endl;
	return 0;
}
////////////////