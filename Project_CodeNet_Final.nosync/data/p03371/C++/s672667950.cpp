#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,x,y;
	int sum1,sum2;
	cin>>a>>b>>c>>x>>y;
	if(x<y)
	{
		sum1=2*x*c+(y-x)*b;
		sum2=2*c*x+2*(y-x)*c;
	}
	else
	{
		sum1=2*y*c+(x-y)*a;
		sum2=2*c*y+2*(x-y)*c;
	}
	 
	int m = a*x+y*b;
	cout<<min(sum1,min(sum2,m));
 } 