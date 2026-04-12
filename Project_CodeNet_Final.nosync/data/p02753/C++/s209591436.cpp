#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 1005;

int main() {

	FAST;

	string s;
	cin >> s;
	set <char> ss;
	ss.insert(s[0]);
	ss.insert(s[1]);
	ss.insert(s[2]);
	cout << ((ss.size() == 2) ? "Yes\n" : "No\n");
	return 0;
}