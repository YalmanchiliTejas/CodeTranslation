#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
const long long Mod=1e9+7;
struct node
{
	long long x,y;
};
int n,h[110];
long long pw(long long x,long long y)
{
	long long res=1;
	while (y)
	{
		if (y&1)
		{
			res=res*x%Mod;
		}
		y>>=1;
		x=x*x%Mod;
	}
	return res;
}
node work(int l,int r,int lim)
{
	node res;
	if (l==r)
	{
		res.x=0;
		res.y=pw(2,h[l]-lim);
		return res;
	}
	int mn=l;
	for (int i=l+1;i<=r;i++)
	{
		if (h[i]<h[mn])
		{
			mn=i;
		}
	}
	node x,y;
	if (mn==l)
	{
		y=work(mn+1,r,h[mn]);
		res.x=(y.x+y.y)*2%Mod;
		res.y=y.y*pw(2,h[mn]-lim)%Mod;
	}
	else if (mn==r)
	{
		x=work(l,mn-1,h[mn]);
		res.x=(x.x+x.y)*2%Mod;
		res.y=x.y*pw(2,h[mn]-lim)%Mod;
	}
	else
	{
		x=work(l,mn-1,h[mn]);
		y=work(mn+1,r,h[mn]);
		res.x=(x.x*y.x%Mod*2%Mod+x.x*y.y%Mod*4%Mod+x.y*y.x%Mod*4%Mod+x.y*y.y%Mod*6%Mod)%Mod;
		res.y=x.y*y.y%Mod*pw(2,h[mn]-lim)%Mod;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	long long ans;
	node res=work(1,n,0);
	ans=(res.x+res.y)%Mod;
	printf("%lld\n",ans);
    return 0;
}