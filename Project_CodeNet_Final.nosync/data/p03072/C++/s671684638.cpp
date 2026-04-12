#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[23],ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		bool ok=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[i])
			ok=0;
		}
		if(ok)
		ans++;
	}
	cout<<ans;
	return 0;
}
