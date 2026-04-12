#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	
	cin>>n;
	
	int h[n+1], i, maxv=0, t;
	
	for(i=1; i<=n; i++)
	{
	    cin>>h[i];
	}
	
	for(i=1; i<=n; i++)
	{
		if(h[i]>=maxv)
		{
			t++;
			maxv=h[i];
		}
	}
	
	cout<<t<<endl;
	
	return 0;
}