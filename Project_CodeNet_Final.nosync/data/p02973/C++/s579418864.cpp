#include<bits/stdc++.h>
using namespace std;
const int maxn=(1e5+10);
int n,a[maxn];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> v;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(v.size()==0)
		{
			++cnt;
			v.push_back(a[i]);
			continue;
		}
		if(a[i]<=v[0])
		{
			++cnt;
			v.insert(v.begin(),a[i]);
			continue;
		}
		int tmp=lower_bound(v.begin(),v.end(),a[i])-v.begin();
		--tmp;
		v.erase(v.begin()+tmp);
		v.insert(v.begin()+tmp,a[i]);
	}
	cout<<cnt<<endl;
	return 0;
}