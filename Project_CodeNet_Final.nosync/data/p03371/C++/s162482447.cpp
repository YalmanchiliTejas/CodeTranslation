#include<iostream>
using namespace std;
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c;
	cin>>x>>y;
	int sum=0;
	if(x>y)
	{
		if(a+b>2*c)
		{
			sum+=2*c*y;
			if(a>2*c)
			{
				sum+=2*c*(x-y);
			}
			else
			{
				sum+=a*(x-y);
			}
		}
		else
		{
			sum+=a*x+b*y;
		}
	}
	if(y>x)
	{
		if(a+b>2*c)
		{
			sum+=2*c*x;
			if(b>2*c)
			{
				sum+=2*c*(y-x);
			}
			else
			{
				sum+=b*(y-x);
			}
		}
		else
		{
			sum+=a*x+b*y;
		}
	}
	if(x==y)
	{
		if(a+b>2*c)
		{
			sum+=2*c*x;
		}
		else sum+=(a+b)*x;
	}
	cout<<sum<<endl;
	return 0;
}