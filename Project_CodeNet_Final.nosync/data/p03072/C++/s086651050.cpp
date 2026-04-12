#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,h[20],max=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
		if(h[i]>=max)
		{
			ans++;
			max=h[i];
		}
	}
	cout<<ans;
	return 0;
}