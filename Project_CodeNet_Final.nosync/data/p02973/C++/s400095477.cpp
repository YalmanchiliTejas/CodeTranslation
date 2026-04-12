#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<int> v;
	for(int i = 0;i<n;i++)
	{
		auto x = upper_bound(v.begin(),v.end(),a[i],greater<>());
		if(x==v.end())
		{
			v.push_back(a[i]);
		}
		else
		{
			*x = a[i];
		}
		
	}
	cout<<v.size()<<endl;
	return 0;
}