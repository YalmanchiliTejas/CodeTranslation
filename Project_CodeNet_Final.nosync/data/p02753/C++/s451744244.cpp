#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	if (S.find('A') == string::npos || S.find('B') == string::npos) {
		cout << "No" << '\n';
	} else {
		cout << "Yes" << '\n';
	}

	return 0;
}
