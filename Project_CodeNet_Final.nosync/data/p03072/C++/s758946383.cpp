#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,ans=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ch;
		cin>>ch;
		if(ch>=x)
		{
			ans++;
			x=ch;
		}
	}
	cout<<ans<<endl;
	return 0;
}