#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int a,b,c,x,y,d=0,s=0,t;
	cin>>a>>b>>c>>x>>y;
	if(x>y)
	{
		d=x-y;
		t=d*a;
		x=x-d;
		
	}
	else
	{
		d=y-x;
		t=d*b;
		y=y-d;
		
	}
	int u,v;
	u=(x*2)*c;
	v=(x*a)+(x*b);
	if(u>v)
	{
		s=s+v;
	}
	else
	{
		s=s+u;
	}
	u=(d*c)*2;
	if(u>t)
	{
		s=s+t;
	}
	else
	{
		s=s+u;
	}
	cout<<s<<endl;
}