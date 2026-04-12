#include<queue>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
#define  For(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define rFor(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
using namespace std;
typedef long long LL;
const int N=2000010;
template<typename T>inline T chkmax(T _A,T _B){return _A>_B?_A:_B;}
template<typename T>inline T chkmin(T _A,T _B){return _A<_B?_A:_B;}
template<typename T>void read(T&x)
{
    x=0;int _f(0);char ch=getchar();
    while(!isdigit(ch))_f|=(ch=='-'),ch=getchar();
    while( isdigit(ch))x=x*10+ch-'0',ch=getchar();
    x=_f?-x:x;
}
inline void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
int n,a[N],rev;
deque<int>q;
int main()
{
	read(n);
	For(i,1,n)read(a[i]);
	For(i,1,n)
	{
		if(rev)
			q.push_front(a[i]);
		else
			q.push_back(a[i]);
		rev^=1;
	}
	if(rev)
	{
		while(!q.empty())
		{
			printf("%d ",q.back());
			q.pop_back();
		}
	}
	else
	{
		while(!q.empty())
		{
			printf("%d ",q.front());
			q.pop_front();
		}
	}
	puts("");
	return 0;
}
