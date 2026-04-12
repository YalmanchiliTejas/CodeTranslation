#include <iostream>

using namespace std;

int x,y,z;

int main ()
{
	cin>>x>>y>>z;
	x=x-z;
	cout<<x/(y+z);
	return 0;
}