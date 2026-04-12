#include <iostream>
using namespace std;
int main()
{
	int n,total=0,x=15;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		total+=800;
		if(i%x==0)
		{
			total-=200;
			x+=15;
		}
	}
	cout<<total;
}