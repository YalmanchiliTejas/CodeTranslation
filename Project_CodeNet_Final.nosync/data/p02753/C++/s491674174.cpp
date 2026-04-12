#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	set<char> ss;
	for (auto c : s) ss.insert(c);
	if (ss.size() > 1) cout << "Yes\n";
	else cout << "No\n";
}
