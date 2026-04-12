#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int counter[n][26] = {};
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		for (int j = 0; j < S.size(); j++) {
			counter[i][S[j] - 'a']++;
		}
	}
	int MINI[26] = {};
	for (int i = 0; i < 26; i++) {
		int mini = 100;
		for (int j = 0; j < n; j++) {
			if (counter[j][i] < mini) mini = counter[j][i];
		}
		MINI[i] = mini;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < MINI[i]; j++) {
			printf("%c", i + 'a');
		}
	}
	cout << endl;
	return 0;
}