#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y;
int main()
{
	cin>>a>>b>>c>>x>>y;
	if(c*2>=a+b)cout<<x*a+y*b<<endl;
	else
	{
		int ans=0;
		if(x==y)cout<<(x+y)*c<<endl;
		else if(x<y)
		{
			ans=(x+x)*c;
			y-=x;
			cout<<ans+min(2*y*c,y*b)<<endl;
		}
		else
		{
			ans=(y+y)*c;
			x-=y;
			cout<<ans+min(2*x*c,x*a)<<endl;
		}
	}
	return 0;
} 