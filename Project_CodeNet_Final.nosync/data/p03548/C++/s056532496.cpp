#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x,y,z,i;
	cin>>x>>y>>z;
	for(i=x/y;i>0;i--)
	{
		if((i*y+(i+1)*z)<=x)break;
	}
	cout<<i<<endl;
	return 0;
} 