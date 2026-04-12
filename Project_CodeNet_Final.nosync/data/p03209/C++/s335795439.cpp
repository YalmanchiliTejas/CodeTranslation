#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

inline long long read()
{
    char c;long long out=0,f=1;
    for (c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
    if (c=='-'){f=-1;c=getchar();}
    for (;c>='0'&&c<='9';c=getchar()){out=(out<<3)+(out<<1)+c-'0';}
    return out*f;
}
void write(long long x)
{
	if (x<0){putchar('-');write(-x);return;}
    if (x>9){write(x/10);}
	putchar(x%10+'0');
}

void work(int a);

long long n,x,ans,f[60],g[60];

int main()
{
	int i;
	
	cin>>n>>x;
	
	f[0]=g[0]=1;
	
	for (i=1;i<=n;++i)
	{
		f[i]=f[i-1]*2+3;
		g[i]=g[i-1]*2+1;
	}
	
	work(n);
	
	cout<<ans;
	
	return 0;
}

void work(int a)
{
	if (x==0)
	{
		return;
	}
	if (a==0)
	{
		--x;
		++ans;
	}
	else if (x>=f[a])
	{
		x-=f[a];
		ans+=g[a];
	}
	else if (x<=f[a-1]+1)
	{
		--x;
		work(a-1);
	}
	else
	{
		x-=f[a-1]+2;
		ans+=g[a-1]+1;
		work(a-1);
	}
}