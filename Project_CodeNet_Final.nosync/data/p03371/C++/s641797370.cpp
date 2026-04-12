#include<bits/stdc++.h>
#define maxn 100007
#define inf 1000000007
#define ll long long int
using namespace std;

int a,m=inf;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void writ(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) writ(x/10);
	putchar(x%10+'0');
}
inline void write(int x){writ(x);putchar('\n');}

int main()
{
	int ans=0,a=read(),b=read(),c=read()<<1,x=read(),y=read();
	if (c<=a+b)
	{
		ans+=min(x,y)*c;
		ans<<1;
		int t=x;
		x=max(0,x-y),y=max(0,y-t);
	}
	if (c<=a) ans+=c*x,x=0;
	if (c<=b) ans+=c*y,y=0;
	ans+=a*x+b*y;
	write(ans);
	return 0;
}