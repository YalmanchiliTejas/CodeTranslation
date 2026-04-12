#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
const int MaxN = 1e3;

int a[MaxN + 5];

int main()
{
	int a,b,c,x,y,n,sum,ans;
	while(~scanf("%d %d %d %d %d",&a,&b,&c,&x,&y))
	{
		ans = 0;
		sum = x;
		n = y;
		if(a + b > 2*c)
		{
			ans += min(sum,n)*2*c;
			x -= min(sum,n);
			y -= min(n,sum);
		}
		if(a > 2*c)
		{
			ans += x*2*c;
			x = 0;
			y -= x;
		}
		if(y < 0) y = 0;
		if(b > 2*c)
		{
			ans += y*2*c;
			y = 0;
			x -= y;
		}
		if(x < 0) x = 0;
		ans += a * x;
		ans += b * y;
		printf("%d\n",ans);
	}
	return 0;
}