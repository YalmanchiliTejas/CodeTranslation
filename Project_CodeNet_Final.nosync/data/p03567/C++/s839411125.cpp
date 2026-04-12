#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;
	bool ok = false;
	int N = S.size();
	for (int i = 1; i < N; i++) {
		if (S.substr(i - 1, 2) == "AC") {
			ok = true;
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}
