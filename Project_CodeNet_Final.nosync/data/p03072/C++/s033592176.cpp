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
	int maxn=a[0];
	int sum=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>=maxn)
		{
			sum++;
			maxn=a[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}
