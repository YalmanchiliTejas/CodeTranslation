#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define  For(i,a,b) for(int i=a,i##E=b;i<=i##E;++i)
#define rFor(i,a,b) for(int i=a,i##E=b;i>=i##E;--i)
typedef long long LL;
using namespace std;
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
string S;
int main()
{
	file();
	cin>>S;
	if(S.find("AC")<S.length())puts("Yes");
	else puts("No");
	return 0;
}
