#include<iostream>
using namespace std;
int main()
{
	int n;
	int h[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	int sum=h[0],ans=1;
	//cout<<sum;
	for(int i=0;i<n;i++)
	{
		if(sum<=h[i])
		{
			sum=h[i];
			ans++;
		}
		else
		{
		}
	}
	cout<<ans-1;
}