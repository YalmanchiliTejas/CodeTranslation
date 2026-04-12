#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv []) {
	int n;
	int ch_count[26];

	for (int i = 0; i < 26; i++) ch_count[i] = 50 * 50 + 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string S;
		cin >> S;

		int cnt[26] = {};
		for (char c : S) {
			cnt[c - 'a']++;
		}

		for (int j = 0; j < 26; j++) ch_count[j] = min(ch_count[j], cnt[j]);
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < ch_count[i]; j++) {
			printf("%c", i + 'a');
		}
	}
	printf("\n");
	return 0;
}