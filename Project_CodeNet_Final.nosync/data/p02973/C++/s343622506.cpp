#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000];
int mn,ans=1;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<int> d;
	for(int i=0;i<n;i++)
	{
		a[i]=-a[i];
	}
	for(int i=0;i<n;i++)
	{
		int pos=upper_bound(d.begin(),d.end(),a[i])-d.begin();
		if(pos==d.size()||d[pos]==a[i])
		d.push_back(a[i]);
		else
		d[pos]=a[i];
	}
	cout<<d.size();
	return 0;
}
