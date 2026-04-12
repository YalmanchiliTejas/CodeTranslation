#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n+20],i,maxv=0,total;
	
	for(i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>=maxv)
		{
			total++;
			maxv=a[i];
		}
	}
	cout<<total<<endl;
	return 0;
}