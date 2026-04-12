#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> abc(26);
	cin >> n;
	vector<string> s(n);
	for (string& in : s)
		cin >> in;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			if (i)
				abc.at(j) = min((int)count(s.at(i).begin(), s.at(i).end(), 'a' + j), abc.at(j));
			else
				abc.at(j) = (int)count(s.at(i).begin(), s.at(i).end(), 'a' + j);
		}
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < abc.at(i); j++)
			cout << (char)('a' + i);
	cout << endl;
}