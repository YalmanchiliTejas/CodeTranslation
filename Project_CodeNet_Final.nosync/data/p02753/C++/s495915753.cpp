#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 1005;

int main() {

	FAST;

	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
	return 0;
}