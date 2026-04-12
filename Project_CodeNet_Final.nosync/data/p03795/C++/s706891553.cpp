#include<iostream>
using namespace std;
int n,x,y;
int main()
{
	cin>>n;
	x=n*800;
	n=(n-n%15)/15;
	y=n*200;
	cout<<x-y<<endl;
	return 0;
}