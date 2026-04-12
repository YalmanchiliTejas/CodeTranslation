#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	int sum=0,ans=0;
	sum=x-z;
	ans=y+z;
	cout<<sum/ans;
	return 0;
}