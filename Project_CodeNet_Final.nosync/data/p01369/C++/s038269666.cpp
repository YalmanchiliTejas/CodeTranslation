#include <iostream>
#include <string>

using namespace std;

int main() {
	string ss = "qwertasdfgzxcvb";

	string s;
	while (cin >> s) {
		if (s == "#") {
			break;
		}
		int aa = -1;
		int cc = 0;
		for (int i = 0; i < s.size(); i++) {
			int bb = 1;
			for (int j = 0; j < ss.size(); j++) {
				if (s[i] == ss[j]) {
					bb = 0;
					break;
				}
			}
			if (i == 0) {
				aa = bb;
			}
			else {
				if (aa != bb) {
					cc++;
					aa = bb;
				}
			}
		}
		cout << cc << endl;
	}

	return 0;
}
