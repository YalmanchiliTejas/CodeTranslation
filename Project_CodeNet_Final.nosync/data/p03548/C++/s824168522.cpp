#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	x=x-z;
	int ans;
	ans=x/(y+z);
	cout<<ans;
}