#include <iostream>
#include <cstdio>

using namespace std;

int x,q,y;
int main()
{
	cin>>x>>q>>y;
	x-=y;
	cout<<x/(q+y)<<'\n';
	return 0;
}