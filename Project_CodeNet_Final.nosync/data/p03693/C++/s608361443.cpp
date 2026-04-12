#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((10*b+c)%4==0)
	{
		cout<<"YES"<<endl;
    }
	else if((10*b+c)%4!=0)
	{
		cout<<"NO"<<endl;
	}
	return 0;
}