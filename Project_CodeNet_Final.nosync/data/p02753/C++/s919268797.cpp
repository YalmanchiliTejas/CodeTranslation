#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;

	string ans = "Yes";
	if (s.at(0) == s.at(1) && s.at(1) == s.at(2) && s.at(2) == s.at(0)) ans = "No";
	cout << ans << endl;
}
