#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int x,y,z,h,g;
int main()
{
	cin>>x>>y>>z;
	h=x-z;
	while(h-y>0)
	{
		if(h-y-z<0)break;
		else h=h-y-z;
		g++;
	}
	cout<<g<<endl;
	return 0;
}