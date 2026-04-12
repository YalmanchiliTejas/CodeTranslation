#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int n, k;
	string s;
	cin >> n >> s >> k;
	for (int i = 0; i < n; i++)
	{
		cout << (s[i] == s[k-1] ? s[k-1] : '*');
	}
	cout << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
