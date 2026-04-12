#include "bits/stdc++.h"
using namespace std;

int main()
{
	string s;
	cin >> s;

	string ans = "Yes";
	if (s[0] == s[1] && s[1] == s[2]) {
		ans = "No";
	}
	
	cout << ans << endl;
}
