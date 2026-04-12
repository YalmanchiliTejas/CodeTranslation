#include <iostream>
#include <string>
using namespace std;

string _left = "qwertasdfgzxcvb";
bool isLeft[26];

int main() {
	int i;
	string s;
	
	for (i = 0; i < _left.length(); i++) isLeft[_left[i] - 'a'] = true;
	while (cin >> s) {
		if (s == "#") break;
		
		bool dir = isLeft[s[0] - 'a'];
		int ans = 0;
		for (int i = 1; i < s.length(); i++) {
			if (dir != isLeft[s[i] - 'a']) {
				dir = isLeft[s[i] - 'a'];
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}