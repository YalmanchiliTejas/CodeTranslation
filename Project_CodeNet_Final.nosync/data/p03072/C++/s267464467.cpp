#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	int look=a[0];
	if(n==1){cout<<1; return 0;}
	for(int i=1;i<n;i++)
	{
		if(a[i]>=a[i-1]&&a[i]>=look)
		{
			look=a[i];
			cnt++;
		}
	}
	cout<<cnt+1;
}

		
			