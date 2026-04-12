#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 1005;

int main() {

	FAST;

	string s;
	cin >> s;
	sort(s.begin(), s.end());
	cout << ((s[0] == s[2]) ? "No\n" : "Yes\n");
	return 0;
}