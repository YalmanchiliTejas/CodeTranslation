#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n;
int a[200005];
int b[200005];
int main()
{
	read(n);
	for(int i=0;i<n;i++)
	{
		read(a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]<=b[n/2-1])
			printf("%d\n",b[n/2]);
		else
			printf("%d\n",b[n/2-1]);
	}
	return 0;
}