#include<bits/stdc++.h>
using namespace std;
long long a[222222];
long long d=1e9+7;
int main()
{
	int n;cin>>n;
	long long sum=0,he=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i]*he;
		he+=a[i];
		sum%=d;
		he%=d;
	} 
		
	
	cout<<sum;
	return 0;

}