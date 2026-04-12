#include <bits/stdc++.h>
     
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	priority_queue <int,vector<int>,greater<int>> pque;
	int n,t;
	multiset <int,greater<int>> s;
	vector <int> v;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}

	s.insert(v[0]);
	for(int i=1;i<n;i++)
	{
		auto it = s.upper_bound(v[i]);
		if(it!=s.end())
		{
			s.erase(s.find(*it));
			s.insert(v[i]);
		}
		else
		{
			s.insert(v[i]);
		}
	}

	cout << s.size() << '\n';

	return 0;
}

