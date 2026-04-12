#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
vector<int> v;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;i++)
	{
		bool b=1;
		vector<int>::iterator k=upper_bound(v.begin(),v.end(),-a[i]);
		if (k==v.end()) v.push_back(-a[i]);
		else *k=-a[i];
	}
	cout<<v.size()<<endl;
	return 0;
}
