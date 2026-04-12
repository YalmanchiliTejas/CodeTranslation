#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int mini=0;
	int c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c>=mini)
		{
			ans++;
			mini=c;
		}
	}
	cout<<ans;
}