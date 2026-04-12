#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int a,b,c,x,y,money=0;
	cin>>a>>b>>c>>x>>y;
	if(a+b<2*c)
	{
		money=a*x+b*y;
		cout<<money;
	}
	if(a+b>=2*c)
	{
		money=c*min(x,y)*2;
		if(x<y)
		{
			money=money+min((y-x)*b,(y-x)*c*2);
			cout<<money;
		}
		if(x>y)
		{
			money=money+min((x-y)*a,(x-y)*c*2);
			cout<<money;
		}
		if(x==y)
		cout<<money;
	}
	return 0;
}