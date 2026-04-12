#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define For(i,a,b) for(i=(a),i<=(b);++i)
#define Forward(i,a,b) for(i=(a),i>=(b);--i)
#define Chkmax(a,b) a=a>b?a:b
#define Chkmin(a,b) a=a<b?a:b
template<typename T>inline void read(T &x)
{
	T f=1;x=0;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c^48);
	x*=f;
}
using namespace std;
const int MAXN=1010;
static int n,k;
inline void init()
{
	read(n);read(k);
}
static long long ans;
inline void solve()
{
	ans=1ll*(n-k)*(n-k+1)/2;
	static int las;
	Rep(l,k,n-1)for(register int i=l+1;i<=n-l;i=las+1)
	{
		las=(n-l)/((n-l)/i);
		ans+=(n-l)/i*(las-i+1);
	}
	if(k==0)cout<<1ll*n*n<<endl;
	else cout<<ans<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}

