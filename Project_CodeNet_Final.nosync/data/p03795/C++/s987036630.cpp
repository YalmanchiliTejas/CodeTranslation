#include <iostream>
using namespace std;
int main()
{
	int n;
	int minus;
	cin>>n;
	if(n>15)
	{
		minus=n/15*200;
	}
	cout<<n*800-minus<<endl;
	return 0;
}