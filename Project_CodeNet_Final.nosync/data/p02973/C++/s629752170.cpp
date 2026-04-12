#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int a[maxn];
multiset<int,greater<int> >s;
multiset<int,greater<int> >::iterator it;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	s.insert(a[0]);
	for(int i=1;i<n;i++)
	{
		it=s.upper_bound(a[i]);
		if(it==s.end())
		{
			s.insert(a[i]);
		}
		else
		{
			s.erase(it);
			s.insert(a[i]);
		}
	}
	cout<<s.size();
	return 0;
}