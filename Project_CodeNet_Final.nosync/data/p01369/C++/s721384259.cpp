#include <iostream>
#include <map>
#include <cstring>

using namespace std;

char group[2][100] = {
	"qwertasdfgzxcvb",
	"yuiophjklnm",
};

int main() {
	map<char, int> m;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < strlen(group[i]); ++j) {
			m[group[i][j]] = i;
		}
	}
	string str;
	while ( cin >> str, str != "#" ) {
		int bid = -1;
		int ans = 0;
		for (int i = 0; i < str.size(); ++i) {
			int g = m[str[i]];
			if (bid != -1 && g != bid) {
				++ans;
			}
			bid = g;
		}
		cout << ans << endl;
	}
}