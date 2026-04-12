#include <iostream>
using namespace std;
int main()
{
	int N,sum,x=0;
	cin>>N;
	if(N>=15)
	{
		x=N/15;
		x=x*200;
	}
	sum=(N*800)-x;
	cout<<sum;

	return 0;
}