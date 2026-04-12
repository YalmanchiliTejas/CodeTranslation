#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> c(26, INT_MAX);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int b[26] = {};
		for (auto&& si : s) b[si-'a']++;
		for (int i = 0; i < 26; i++) c[i] = min(c[i], b[i]);
	}
	string r;
	for (int i = 0; i < 26; i++) r += string(c[i], (char)(i+'a'));
	cout << r << endl;
	return 0;
}
