#include<iostream>
using namespace std;
int a,b,c,xx,yy,rs;
int main()
{
	cin>>a>>b>>c>>xx>>yy;
	if(a+b<2*c)
	{rs=xx*a+yy*b;}
	else
	{
		if(xx>yy)
		{rs=2*c*yy;if(2*c<a)rs+=(xx-yy)*c*2;else rs+=(xx-yy)*a;
		}
		else 
		{rs=2*c*xx;if(2*c<b)rs+=(-xx+yy)*c*2;else rs+=(-xx+yy)*b;
		}
	}
	cout<<rs<<endl;
}