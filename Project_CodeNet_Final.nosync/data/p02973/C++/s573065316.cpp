#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int n;
	cin >> n;
	vector<int> s;
	while(n--)
	{
		int x;
		cin >> x;
		auto i = lower_bound(s.begin(), s.end(), -x+1);
		if (i == s.end()) s.push_back(-x);
		else *i = -x;
	}
	cout << s.size() << '\n';
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

