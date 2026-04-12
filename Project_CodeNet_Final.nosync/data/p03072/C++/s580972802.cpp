#include<bits/stdc++.h>
using namespace std;
int n,h[20],maxn=0,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
		if(h[i]>=maxn)
		{
			ans++;
			maxn=h[i];
		}
	}
	cout<<ans;
}
