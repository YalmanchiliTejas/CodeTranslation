#include <bits/stdc++.h>

using namespace std;

int main() {

	long n;
	cin >> n;

	vector<string> s(n);
	for (long i = 0; i < n; i++) {
		cin >> s[i];
	}

	vector<vector<long>> ab(n,vector<long> (26,0));

	for (long i = 0; i < n; i++) {
		for (long j = 0; j < s[i].size(); j++) {
			ab[i][s[i][j]-97]++;
		}
	}

	long counter ;
	for (long j = 0; j < 26; j++) {
		counter = 100;
		for (long i = 0; i < n; i++) {
			counter = min(counter, ab[i][j]);
		}
		for (long k = 0; k < counter; k++) {
			cout << (char)(j + 97);
		}
	}
	cout << endl;
	return 0;

}