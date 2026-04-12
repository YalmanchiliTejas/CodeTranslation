#include<bits/stdc++.h>
using namespace std;
int x,y,z,s; 
int main()
{
	cin>>x>>y>>z;
	x-=z;
	while(x>=y+z)
	{
		x-=y+z;
		s++; 
	}
	cout<<s<<endl;
	return 0;
}