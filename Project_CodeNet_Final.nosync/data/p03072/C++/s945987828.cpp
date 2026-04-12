#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,h,m=0,c=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>h;
		if(h>=m)
		{
			m=h;
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}