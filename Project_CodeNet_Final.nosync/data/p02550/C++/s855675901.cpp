#include<bits/stdc++.h>
namespace P_TEMPLATE{
	#define endl '\n'
	#define rgi register int
	typedef long long ll;
	class fastin{private:int _ch,_f;
	public:inline fastin&operator>>(char&c){c=getchar();return*this;}
	template<typename _Tp>inline fastin&operator>>(_Tp&_x){
	_x=0;while(!isdigit(_ch))_f|=(_ch==45),_ch=getchar();
	while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=getchar();
	_f&&(_x=-_x,_f=0);return*this;}fastin(){_ch=_f=0;}
	}fin;class fastout{private:int _num[32],_head;
	public:inline fastout&operator<<(char c){putchar(c);return*this;}
	template<typename _Tp> inline fastout&operator<<(_Tp _x){
	_Tp _k;if(_x==0){putchar('0');return *this;}if(_x<0)putchar('-'),_x=-_x;
	while(_x>0)_k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
	while(_head>0)putchar(_num[_head]),--_head;return*this;}fastout(){_head=0;}
	}fout;inline void P_INIT(){
	#ifdef D_STDOUT_UNBUFFERED
	setbuf(stdout,NULL),setbuf(stdin,NULL);
	#endif
}}using namespace P_TEMPLATE;
// ----------------------------
// #define int ll
using namespace std;
const int maxn=200004;
const int mod=998244353,inf=1201201201;

int pos[maxn];
ll sum[maxn];
signed main()
{P_INIT();
	ll n,m,x,p,ans;
	fin>>n>>x>>m;
	pos[x]=1,sum[1]=x;
	for(p=2;p<=std::min(n,m+10);++p) {
		x=(x*x)%m;
		sum[p]=sum[p-1]+x;
		if(pos[x]) break;
		pos[x]=p;
	}
	if(p>n) fout<<sum[n];
	else {
		ans=sum[pos[x]],n-=pos[x];
		ans+=(sum[p]-sum[pos[x]])*(n/(p-pos[x]));
		n%=p-pos[x];
		ans+=sum[pos[x]+n]-sum[pos[x]];
		fout<<ans;
	}
	return 0;
}
// ----------------------------
// by imzzy