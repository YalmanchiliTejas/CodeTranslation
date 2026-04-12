#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool b = false;
	for (int i=0;i<s.size();++i) {
		if (s[i] == 'A' && i+1<s.size() && s[i+1] == 'C') b = true;
	}
	if (b) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}