#include<cstdio>
#include<iostream>
using namespace std;
int n;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main()
{
	n=read();
	if(n>=30)puts("Yes");
	else puts("No");
	return 0;
}