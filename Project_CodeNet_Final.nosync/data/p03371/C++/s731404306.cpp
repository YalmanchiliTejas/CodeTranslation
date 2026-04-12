#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<vector>
#include<string> 
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,x,y,ans;
	cin>>a>>b>>c>>x>>y;
	if(a+b>2*c)
	{
		if(x>y)
		{
			ans=c*2*y;
			if(c*2<a)
			ans+=c*2*(x-y);
			else ans+=a*(x-y);
		}
		else {
			ans=c*2*x;
			if(c*2<b)
			ans+=c*2*(y-x);
			else ans+=b*(y-x);
		}
	}
	else ans=a*x+b*y;
	printf("%d\n",ans);
	return 0;
}