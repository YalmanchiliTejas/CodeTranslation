#include<iostream>
using namespace std;
int x,y,n,ans;
int main()
{
	cin>>n;
	x=800*n;
	y=(n/15)*200;
	ans=x-y;
	cout<<ans<<endl;
	return 0;
}