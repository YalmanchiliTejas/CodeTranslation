#include<iostream>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=1;i<=x;i++)
	if((y+z)*i+z>x)
	{
		cout<<i-1<<endl;
		return 0;
	}
}