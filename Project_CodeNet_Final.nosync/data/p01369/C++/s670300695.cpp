#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string left = "qwertasdfgzxcvb";
	sort(left.begin(), left.end());

	string s;
	while (cin >> s) {
		if (s == "#")
			break;

		int ans = 0;
		bool l = false;
		if (binary_search(left.begin(), left.end(), s[0]))
			l = true;

		for (int i = 1; i < s.size(); ++i) {
			if (l) {
				if (!binary_search(left.begin(), left.end(), s[i])) {
					l = false;
					++ans;
				}
			} else {
				if (binary_search(left.begin(), left.end(), s[i])) {
					l = true;
					++ans;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}