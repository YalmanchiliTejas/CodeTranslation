#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define pb push_back
#define pii pair<int,int>
#define SZ(x) (int)x.size()
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define  For(i,a,b) for(int i=a,i##E=b;i<=i##E;++i)
#define rFor(i,a,b) for(int i=a,i##E=b;i>=i##E;--i)
typedef long long LL;
using namespace std;
const int inf=0x3f3f3f3f;
template<typename T>inline bool chkmin(T &a,const T &b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T &a,const T &b){return a<b?a=b,1:0;}
template<typename T>inline void read(T &x)
{
	x=0;int _f(0);char ch=getchar();
	while(!isdigit(ch))_f|=(ch=='-'),ch=getchar();
	while( isdigit(ch))x=x*10+ch-'0',ch=getchar();
	x=_f?-x:x;
}
inline void file()
{
#ifdef ztzshiwo
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
}
LL n,K;
LL ans;
int main()
{
	file();
	read(n),read(K);
	if(K==0)printf("%lld\n",1ll*n*n);
	else
	{
		For(i,K+1,n)
		{
			ans+=n/i*(i-K);
			ans+=max(n%i-K+1,0ll);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
