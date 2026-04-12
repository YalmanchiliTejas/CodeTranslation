#include "bits/stdc++.h"
using namespace std;


int main()
{
	int n, k;
	string s;
	cin >> n >> s >> k;

	char c = s[k - 1];

	string ans = "";
	for (char s_ele : s) {
		if (s_ele == c) {
			ans += s_ele;
		} else {
			ans += '*';
		}
	}

	cout << ans << endl;
}