#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int a[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	v.push_back(-1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v.size();j++)
			if (a[i]>v[j])
			{
				v[j]=a[i];
				break;
			}
			else if (a[i]<=v[v.size()-1])
			{
				v.push_back(a[i]);
				break;
			}
	}
	cout<<(int)v.size();
	return 0;
}