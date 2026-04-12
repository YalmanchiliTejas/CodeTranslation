#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y,yen;
	cin>>a>>b>>c>>x>>y;
	if(a+b>2*c)
	{
		if(x>y)
		{
			if((2*y*c+(x-y)*a)>2*x*c) yen=2*x*c;
			else yen=2*y*c+(x-y)*a;
		}
		else
		{
			if((2*x*c+(y-x)*b)>2*y*c) yen=2*y*c;
			else yen=2*x*c+(y-x)*b;
		}
		
	}
	else yen=a*x+b*y;
	cout<<yen<<endl;
	return 0;
}