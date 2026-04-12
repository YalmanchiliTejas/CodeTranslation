#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	set<char> c;
	for (int i=0;i<s.size();i++)
		c.insert(s[i]);
	if (c.size() == 1) cout << "No";
	else cout << "Yes";	
}