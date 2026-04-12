#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	bool is_a = false, is_b = false;
	for (char c : s) {
		if (c == 'A')
			is_a = true;
		if (c == 'B')
			is_b = true;
	}
	if (is_a && is_b)
		cout << "Yes";
	else
		cout << "No";
	cout << "\n";
}

