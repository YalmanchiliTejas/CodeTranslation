#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	for (int i = 1; i < (int)s.size(); ++i) {
		if (s[i] == 'C' && s[i-1] == 'A') return printf("Yes\n"), 0;
	}
	printf("No\n");
}