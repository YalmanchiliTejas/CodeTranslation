#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,sum=0,mini=10000;
int main()
{
	cin>>a>>b>>c>>x>>y;
	if(2*c<=(a+b))
	{
		if(x==y)
		{
			cout<<2*x*c; return 0;
		}
		if(x>y)
		{
			if(a>=2*c)
			{
				cout<<2*x*c; return 0;
			}
			
			else
			{
				cout<<2*y*c+(x-y)*a; return 0;
			}
		}
		if(x<y)
		{
			if(b>=2*c)
			{
				cout<<2*y*c; return 0;
			}
			
			else
			{
				cout<<2*x*c+(y-x)*b; return 0;
			}
		}
	}
	else
	{
		cout<<x*a+y*b;
	}
	return 0; 
} 