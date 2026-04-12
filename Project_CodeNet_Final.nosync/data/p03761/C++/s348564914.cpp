#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int n = 0;
	scanf("%d", &n);
	// printf("%d\n", n);
	vector<vector<int>> S(26, vector<int>(n, 0));
	char c;
	int line = 0;
	scanf("%c", &c);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int j = 0;
		while (true) {
			// printf("[%c]", s[j]);
			if (s[j] < 'a' || s[j] > 'z') {
				// printf("\n");
				if (line >= n) {
					goto finish;
				} else {
					break;
				}
			} else {
				// printf("%c", c);
				S[s[j] - 'a'][i]++;
			}
			j++;
		}
	}
finish:
	for (int i = 0; i < 26; i++) {
		// printf("%c %d\n", 'a' + i, *min_element(S[i].begin(), S[i].end()));
		for (int j = 0; j < *min_element(S[i].begin(), S[i].end()); j++) {
			printf("%c", 'a' + i);
		}
	}

	return 0;
}