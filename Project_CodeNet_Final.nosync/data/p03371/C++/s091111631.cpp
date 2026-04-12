#include<stdio.h> 
#include<stdlib.h>
#include<cstring>
#include<string> 
#include<iostream>
using namespace std;

int main()
{
	int a,b,c,x,y,cost=0;
	cin>>a>>b>>c>>x>>y;
	if(x<y)
	{
		 swap(x,y);
		 swap(a,b);
	}
	if((a+b)> 2*c)
	{
		int p1 = x*2*c;
		int p2 = y*2*c + (x-y)*a;
		cost = min(p1,p2);
	}
	else 
	{
		cost = cost + a*x+b*y;
		x=0;
		y=0;
	}
	cout<<cost<<endl;
	return 0;
}