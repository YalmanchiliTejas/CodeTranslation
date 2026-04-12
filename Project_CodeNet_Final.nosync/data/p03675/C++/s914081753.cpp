#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, i;
	deque<int> dq;
	
	cin>>n;
	
	for (i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		if (i % 2)
			dq.push_front(x);
		else dq.push_back(x);
	}
	
	if (n % 2)
		reverse(dq.begin(), dq.end());
	
	for (i = 0; i < n; ++i)
		cout<<dq[i]<<' ';
	cout<<'\n';
}
