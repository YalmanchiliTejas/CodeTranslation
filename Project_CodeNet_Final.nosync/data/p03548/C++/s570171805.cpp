#pragma GCC optimize(2)
#include <cstdio>
using namespace std;
int a,b,c;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
int main()
{
    a=read(),b=read(),c=read();
    printf("%d\n",(a-c)/(b+c));
    return 0;
}