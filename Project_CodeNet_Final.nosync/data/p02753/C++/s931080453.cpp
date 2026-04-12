#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<bitset>
#define int long long
using namespace std;
const int maxn=100005,mod=1e9+7;
string a;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int a)
{
	if(a<0)
	{
		putchar('-');
		write(-a);
	}
	else
	{
		if(a>=10)
			write(a/10);
		putchar(a%10+'0');
	}
}
signed main()
{
	cin>>a;
	if(a[0]==a[1]&&a[1]==a[2])
		puts("No");
	else
		puts("Yes");
	return 0;
}