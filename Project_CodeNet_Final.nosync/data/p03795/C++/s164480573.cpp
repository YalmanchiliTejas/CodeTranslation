#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a,b;
	cin>>a;
	
	b=ceil(a/15);
	cout<<a*800-b*200;
	
	return 0;
}