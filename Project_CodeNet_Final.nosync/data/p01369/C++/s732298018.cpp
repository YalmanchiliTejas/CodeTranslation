#include <iostream>

using namespace std;

string s = "qwertasdfgzxcvb";
int main() {
	string str;
	while ( cin >> str, str != "#" ) {
		if (str.size() == 0) cout << 0 << endl;
		else {
			int ans = 0;
			bool prev = false;
			for (int i = 0; i < str.size(); ++i) {
				if ((s.find(str[i], 0) != -1) ^ prev) {
					if (i) ++ans;
				}
				prev = s.find(str[i], 0) != -1;
			}
			cout << ans << endl;
		}
	}
}