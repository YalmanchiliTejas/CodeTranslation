#include <bits/stdc++.h>

using namespace std;

string A(string& S) {
	unordered_set<char> s(S.begin(), S.end());
	return (s.size() > 1) ? "Yes" : "No";
}

int main() {
	string S;
	cin >> S;
	cout << A(S);
	return 0;
}