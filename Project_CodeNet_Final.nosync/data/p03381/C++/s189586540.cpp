#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<set>
#include<complex>
#include<map>
using namespace std;
inline int ri()
{
	register int x=0;
	bool f=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(f)	return -x;
	else	return x;
}
void wi(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	wi(x/10);
	putchar(x%10+'0');
}
const int N=2e5+7;
struct data
{
	int id,a;
	bool operator <(const data &t)const
	{
		return a<t.a;
	}
}q[N];
int ans[N];
int main()
{
	int n=ri(),i;
	for(i=1;i<=n;i++)	q[i].id=i,q[i].a=ri();
	sort(q+1,q+1+n);
	for(i=1;i<=n/2;i++)	ans[q[i].id]=q[n/2+1].a;
	for(i=n/2+1;i<=n;i++)	ans[q[i].id]=q[n/2].a;
	for(i=1;i<=n;i++)	wi(ans[i]),putchar('\n');
	return 0;
}
/*
4
2 4 4 3





*/