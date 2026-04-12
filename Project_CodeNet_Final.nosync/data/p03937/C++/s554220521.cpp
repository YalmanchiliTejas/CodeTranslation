#include<bits/stdc++.h>
using namespace std;
#include <climits>
#define Sheryang main
typedef long long ll;
#pragma GCC optimize(3)
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > >
template<class T> inline T min(T &x,const T &y){return x>y?y:x;}
template<class T> inline T max(T &x,const T &y){return x<y?y:x;}
int read()
{
    int x=0,f=1;	char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')	{x=x*10+c-'0';c=getchar();}
    return x*f;
}
struct ios
{
	inline char gc()
	{
		static const int IN_LEN=1<<18|1;
		static char buf[IN_LEN],*s,*t;
		return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
	}
	template <typename _Tp> inline ios & operator >> (_Tp&x)
	{
		static char ch,sgn; ch = gc(), sgn = 0;
		for(;!isdigit(ch);ch=gc())
		{	
			if(ch==-1)return *this;sgn|=ch=='-';
		}
		for(x=0;isdigit(ch);ch=gc())x=(((x<<2)+x)<<1)+(ch^'0');
		sgn&&(x=-x); return *this;
	}
}io;
const int maxn = 5e6 + 7;
const int mod = 1e9 + 7;
/** keep hungry and keep calm! **/

int h,w;
int main()
{
	cin >> h >> w;
	int cnt = 0;
	for(int i=1;i<=h;i++)
	{
		getchar();
		for(int j=1;j<=w;j++)
		{
			char ch;
			ch = getchar();
			if(ch == '#')	cnt++;
		}
	}
	if(cnt == h+w-1)	printf("Possible\n");
	else	printf("Impossible\n");
	return 0;
}