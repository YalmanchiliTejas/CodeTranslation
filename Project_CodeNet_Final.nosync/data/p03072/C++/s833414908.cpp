#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,t=0,maxx=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>=maxx)
		t++;
		maxx=max(maxx,a[i]);
	}
	cout<<t<<endl;
	
 } 