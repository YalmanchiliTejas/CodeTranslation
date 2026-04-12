#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }
    int h=1;
    for(int i=2;i<=n;i++)
    {
    	int sum=0;
    	for(int j=i-1;j>=1;j--)
    	{
    		if(a[j]>sum)
    		{
    			sum=a[j];
			}
		}
		if(sum<=a[i])
		{
			h++;
		}
	}
	cout<<h<<endl;
	return 0;
} 