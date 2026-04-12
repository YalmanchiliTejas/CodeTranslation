#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<list>
#include<stack>
#include<cstdio>
#include<fstream>
#include<numeric>
#include<functional>
#include<utility>
#include<memory>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;   
int main()
{
	int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	if (a+b>2*c)
	{
		if (x>y)
		{
			ans=ans+y*2*c+(x-y)*a;
		}
		else
		{
			ans=ans+x*2*c+(y-x)*b;
		}
	}
	else
	{
		ans=ans+a*x+b*y;	
	}
	if (c*max(x,y)*2<ans) ans=c*max(x,y)*2;
	cout<<ans<<endl;
	return 0;
} 