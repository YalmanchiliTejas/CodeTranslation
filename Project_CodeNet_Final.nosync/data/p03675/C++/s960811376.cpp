#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

#define rp(i,t) for(int i=0;i<(t);i++)
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define rsp(i,s,t) for(int i=(s);i<(t);i++)
#define rrp(i,t,s) for(int i=(t);i>=(s);i--)
#define rcp(i,s,b,d) for(int i=(s);b;d)
#define mst(a,x) memset(a,x,sizeof(a))
#define INF 0x3f3f3f3f
#define N

#define Dp puts("")
#define Dw printf
#define Ds printf("#")

typedef long long ll;
bool b;
char ch;
int n,x;
deque<int> Q;

inline void read(int &x){x=0;do{ch=getchar();}while(ch<'0'||'9'<ch);do{x=x*10+ch-'0';ch=getchar();}while('0'<=ch&&ch<='9');}

int main(void)
{
	read(n);
	rep(i,1,n)
	{
		read(x);
		if(b)Q.push_front(x);
		else Q.push_back(x);
		b=!b;
	}
	if(b)
	{
		while(!Q.empty())
		{
			printf("%d ",Q.back());
			Q.pop_back();
		}
	}
	else
	{
		while(!Q.empty())
		{
			printf("%d ",Q.front());
			Q.pop_front();
		}
	}
	return 0;
}
