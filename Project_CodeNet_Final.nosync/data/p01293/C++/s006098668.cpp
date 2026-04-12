#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string tr, s[4][13];
int main() {
	while (cin >> tr, tr != "#") {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				cin >> s[i][j];
			}
		}
		int r = 0, ptr = 0;
		for (int i = 0; i < 13; i++) {
			vector<int> a(4);
			for (int j = 0; j < 4; j++) {
				int c = 0;
				if (s[j][i][1] != s[ptr][i][1] && s[j][i][1] != tr[0]) continue;
				if (s[j][i][0] == 'T') c = 10;
				else if (s[j][i][0] == 'J') c = 11;
				else if (s[j][i][0] == 'Q') c = 12;
				else if (s[j][i][0] == 'K') c = 13;
				else if (s[j][i][0] == 'A') c = 14;
				else c = s[j][i][0] - 48;
				if (s[j][i][1] == tr[0]) c += 13;
				a[j] = c;
			}
			ptr = max_element(a.begin(), a.end()) - a.begin();
			if (ptr & 1) r++;
		}
		if (r > 6) cout << "EW " << r - 6 << endl;
		else cout << "NS " << 7 - r << endl;
	}
	return 0;
}