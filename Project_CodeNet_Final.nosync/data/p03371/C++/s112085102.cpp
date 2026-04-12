#include <iostream>
using std::cin;
using std::cout;
int main()
{
	int a,b,c,x,y;
	long int cost=0;
	cin>>a>>b>>c>>x>>y;
	if(c<((a+b)/2.0))
	{
		if(y>x)
		{
			cost+=x*c*2;
			y=y-x;
			if(c<(b/2.0))
				cost+=y*c*2;
			else
				cost+=y*b;
		}
		else
		{
			cost=y*c*2;
			y=x-y;
			if(c<(a/2.0))
				cost+=y*c*2;
			else
				cost+=y*a;
		}
	}
	else 
		cost=x*a+y*b;
	cout<<cost;
			
			
	return 0;
}
