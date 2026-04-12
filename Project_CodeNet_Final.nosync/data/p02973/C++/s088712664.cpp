#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	multiset<int> memo;
	for (int i = n-1; i >= 0; --i)
	{
		auto itr=memo.upper_bound(a[i]);
		if (itr!=memo.end())
		{
			memo.erase(itr);
		}
		memo.insert(a[i]);
	}
	cout<<memo.size()<<endl;
	return 0;
}
