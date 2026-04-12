#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define iter std::vector<int>::iterator

int main() {
	ios_base ::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	char c = s[0];
	for (int i=1; i < 3; i++) {
		if (c != s[i]) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;	
}