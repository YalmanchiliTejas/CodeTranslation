#include<iostream>
using namespace std;
int ans,n;
int main()
{
	cin>>n;
	int k=n/15;
	int y=k*200;
	int x=n*800;
	cout<<x-y<<"\n";
	return 0;
}