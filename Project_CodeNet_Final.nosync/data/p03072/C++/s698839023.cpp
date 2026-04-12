#include<bits/stdc++.h>
using namespace std;
int n;
int a[20];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int maxn=-1,ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=maxn)
		{
			++ans;
			maxn=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}