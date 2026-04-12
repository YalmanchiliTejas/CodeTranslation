#include <bits/stdc++.h>
using namespace std;

const int N = 51;

int main () {
	int n; cin >> n;
	string in[n];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	int letters[26], temp[26];
	for (int i = 0; i < 26; i++)
		letters[i] = N;
	for (int i = 0; i < n; i++) {
		memset(temp, 0, sizeof temp);
		for (int j = 0; j < in[i].size(); j++)
			temp[in[i][j]-'a']++;
		for (int j = 0; j < 26; j++)
			letters[j] = min(letters[j], temp[j]);
	}

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < letters[i]; j++)
			cout << (char)('a'+i);
	return 0;
}
