#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	map<char, int> min_alphabet;
	for (int i = 0; i < alphabet.size(); i++) min_alphabet[alphabet[i]] = INT_MAX;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map<char, int> check_alphabet;
		for (int j = 0; j < alphabet.size(); j++) check_alphabet[alphabet[j]] = 0;
		for (int j = 0; j < s.size(); j++) check_alphabet[s[j]]++;

		for (int j = 0; j < alphabet.size(); j++) {
			if (check_alphabet[alphabet[j]] < min_alphabet[alphabet[j]]) {
				min_alphabet[alphabet[j]] = check_alphabet[alphabet[j]];
			}
		}
	}

	for (auto& item : min_alphabet) {
		for (int i = 0; i < item.second; i++) cout << item.first;
	}
	cout << endl;
}