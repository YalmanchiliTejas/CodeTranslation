#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n=0;cin>>n;
	pair<int,int> x[200010];
	for(int i=0;i<n;i++)
	{
		cin>>x[i].first;
		x[i].second=i;
	}
	sort(x,x+n);
	
	int ans[200010]={0};
	for(int i=0;i<n;i++)
	{
		int j=x[i].second;
		if(i>=n/2)
		{
			ans[j]=x[n/2-1].first;
		}
		else
		{
			ans[j]=x[n/2].first;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
