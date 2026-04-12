#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	int mn[26];
	fill(mn, mn + 26, 100);
	for (int i = 0; i < n; i++) {
		cin >> s;

		int t[26] = {};
		for (int j = 0; j < s.length(); j++) {
			t[s[j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			mn[j] = min(mn[j], t[j]);
		}
	}
	
	bool f = false;
	for (int i = 0; i < 26; i++) {
		if (mn[i] != 0) {
			f = true;
			break;
		}
	}

	if (f) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < mn[i]; j++) {
				printf("%c", 'a' + i);
			}
		}
		cout << endl;
	} else {
		cout << "" << endl;
	}

	return 0;
}