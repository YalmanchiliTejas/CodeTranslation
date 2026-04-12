#include <iostream>
using namespace std;
int main()
{
	int a,b,c,sum;
	cin>>a>>b>>c;
	sum=(100*a)+(10*b)+c;
	if(sum%4==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}