#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,x,y,sum;
	cin>>a>>b>>c>>x>>y;
	if((a+b)>=c*2)
	{
		if(x>=y)
		{
			if(a<=c*2)  sum=y*2*c+(x-y)*a;
			if(a>c*2)  sum=y*2*c+(x-y)*2*c;
		}
		if(x<y)
		{
			if(b<=c*2)  sum=x*2*c+(y-x)*b;
			if(b>c*2)  sum=x*2*c+(y-x)*2*c;
		}
	}
	if((a+b)<c*2)
	{
		if(x>=y)
		{
			if(a<=c*2)  sum=y*(a+b)+(x-y)*a;
			if(a>c*2)  sum=y*(a+b)+(x-y)*2*c;
		}
		if(x<y)
		{
			if(b<=c*2)  sum=x*(a+b)+(y-x)*b;
			if(b>c*2)  sum=x*(a+b)+(y-x)*2*c;
		}
	}
	cout<<sum<<endl;
	return 0;
}