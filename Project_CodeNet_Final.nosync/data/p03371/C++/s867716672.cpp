#include<bits/stdc++.h>
using namespace std;
main()
{
	int a,b,c,d,e,f=0;
	cin>>a>>b>>c>>d>>e;
	if(a+b<=c*2) f=f+a*d+b*e;
	if(a+b>c*2)
	{
		if(d<=e) 
		{
			if(c*2>=b) f=d*2*c+f+b*(e-d);
			if(c*2<b) f=e*2*c;
		}
		if(d>e) 
		{
			if(c*2>=a) f=e*2*c+f+a*(d-e);
			if(c*2<a) f=d*2*c;
		}
	}
	cout<<f;
	return 0;
} 