#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
long long a,b,c,x,y,s,minn,maxx,z,ans;
int main()
{
	cin>>a>>b>>c>>x>>y;
	s=a+b;
	minn=min(x,y);
	maxx=max(x,y);
	z=maxx-minn;
	if(s>=2*c)
	{
	
	ans+=minn*2*c;
	if(a<=2*c&&x==maxx)
	{
		ans+=z*a;
	}
	else if(a>2*c&&x==maxx)
	{
		ans+=z*2*c;
	}
	else if(b>2*c&&y==maxx)
	{
		ans+=z*2*c;
	}
	else if(a<=2*c&&y==maxx)
	{
		ans+=z*b;
	}	
	}
	else if(s<2*c)
	{
		
	ans+=minn*s;
	if(a<=2*c&&x==maxx)
	{
		ans+=z*a;
	}
	else if(a>2*c&&x==maxx)
	{
		ans+=z*2*c;
	}
	else if(b>2*c&&y==maxx)
	{
		ans+=z*2*c;
	}
	else if(a<=2*c&&y==maxx)
	{
		ans+=z*b;
	}	
	}
	cout<<ans;
	return 0;
	
} 