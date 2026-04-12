#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,z,r=0;
	cin>>x>>y>>z;
	x-=z;
	r=x/(y+z);
	cout<<r<<endl;
	return 0;
}