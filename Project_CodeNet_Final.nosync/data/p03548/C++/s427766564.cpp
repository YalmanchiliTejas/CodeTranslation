#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,b;
	cin>>n>>m>>b;
	cout<<floor((n-b)/(m+b));
	return 0;
}