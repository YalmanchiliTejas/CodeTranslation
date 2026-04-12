#include<bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int x = count(s.begin(), s.end(), 'A');
	int y = count(s.begin(), s.end(), 'B');
	cout << (x != 0 and y != 0 ? "Yes" : "No");
	return 0;
}