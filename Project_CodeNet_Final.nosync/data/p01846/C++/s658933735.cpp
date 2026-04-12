#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		if (s == "#")break;
		bool br[10][10];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)br[i][j] = false;

		int now = 0;
		int rt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'b') {
				br[rt][now] = true;
				now++;
			}
			else if (s[i] == '/') {
				now = 0;
				rt++;
			}
			else {
				now += s[i] - '0';
			}
		}

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		swap(br[a - 1][b - 1], br[c - 1][d - 1]);

		string ans;
		for (int i = 0; i <= rt; i++) {
			int nm = 0;
			for (int j = 0; j < now; j++) {
				if (br[i][j]) {
					if(nm)ans.push_back(nm+'0');
					ans.push_back('b');
					nm = 0;
				}
				else nm++;
			}
			if (nm)ans.push_back(nm + '0');
			ans.push_back('/');
		}
		ans.pop_back();
		cout << ans << endl;
	}
	return 0;
}