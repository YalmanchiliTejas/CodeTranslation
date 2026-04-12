#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 0; i < s.size() - 1; i++)
		if (s.substr(i, 2) == "AC")
			ok = true;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
