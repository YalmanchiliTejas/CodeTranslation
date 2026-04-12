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
struct node
{
	int x,y;
}a[200010];
int n;
long long ans=4e18,mnx=2e9,mny=2e9,mxx,mxy;
multiset<int> sx,sy;
bool cmp(node x,node y)
{
	return x.x<y.x;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y)
		{
			swap(x,y);
		}
		a[i].x=x;
		a[i].y=y;
		sx.insert(x);
		sy.insert(y);
		mxx=max(mxx,1LL*x);
		mxy=max(mxy,1LL*y);
		mnx=min(mnx,1LL*x);
		mny=min(mny,1LL*y);
	}
	sort(a,a+n,cmp);
	ans=min(ans,(mxx-mnx)*(mxy-mny));
	for (int i=0;i<n;i++)
	{
		sx.erase(sx.find(a[i].x));
		sy.insert(a[i].x);
		sy.erase(sy.find(a[i].y));
		sx.insert(a[i].y);
		ans=min(ans,1LL*(*sx.rbegin()-*sx.begin())*(*sy.rbegin()-*sy.begin()));
	}
	printf("%lld\n",ans);
    return 0;
}
//人到情多情转薄，而今真个悔多情。
//——纳兰性德《山花子》