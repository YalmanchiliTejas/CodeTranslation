#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long int n,a[1000],i,j,ans=0,f;
	
	cin>>n;
	
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	ans=1;
	
	for(i=1;i<n;i++)
	{
	    f=0;
	    for(j=0;j<i;j++)
	    {
	        if(a[i]<a[j])
	        {
	            f=1;
	        }
	    }
	    if(f==0)
	    {
	       ans++;
	    }
	}
	
	cout<<ans;
	
	return 0;
}
