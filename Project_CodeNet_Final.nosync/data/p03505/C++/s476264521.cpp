#include<iostream>
long long n,x,y,ans,s;
using namespace std;
int main()
{
	cin>>n>>x>>y;
	if(x>=n) 
	{
		cout<<"1";
		return 0;
	}
	if(y>=x) 
	{
		cout<<"-1";
		return 0;
	}
	if((n-x)%(x-y)>=1) s=1;
	cout<<((n-x)/(x-y)+s)*2+1;
}