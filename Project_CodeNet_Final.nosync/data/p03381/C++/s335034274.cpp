#include<bits/stdc++.h>
using namespace std;
int asd[200005];
int asd1[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>asd[i];
		asd1[i]=asd[i];
	}
	sort(asd1,asd1+n);
	int t=(n+1)/2-1;
	for(int i=0;i<n;i++)
	{
		int a=lower_bound(asd1,asd1+n,asd[i])-asd1;
		if(a<=t)
		{
			cout<<asd1[t+1]<<endl;
		}
		else
		{
			cout<<asd1[t]<<endl;
		}
		
	}
}