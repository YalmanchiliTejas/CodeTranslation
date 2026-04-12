#include <iostream>
#include <string>
using namespace std;

int n;
string str, ans;

bool solve(char s, char e) {
	ans = "";
	for (int i = 0; i < n; i++) {
		ans += s;
		if ((str[i] == 'o' && s == 'S') || (str[i] == 'x' && s == 'W')) {
			char tmp = e;
			e = s;
			s = tmp;
		}
		else if ((str[i] == 'x' && s == 'S') || (str[i] == 'o' && s == 'W')) {
			if (e == 'S') {
				e = s;
				s = 'W';
			} else {
				e = s;
				s = 'S';
			}
		}
	}

	return (str[0] == 'o' && ans[0] == 'S' && ans[1] == ans[n - 1] ||
			str[0] == 'x' && ans[0] == 'S' && ans[1] != ans[n - 1] ||
			str[0] == 'o' && ans[0] == 'W' && ans[1] != ans[n - 1] ||
			str[0] == 'x' && ans[0] == 'W' && ans[1] == ans[n - 1]) &&
		   (str[n - 1] == 'o' && ans[n - 1] == 'S' && ans[0] == ans[n - 2] ||
			str[n - 1] == 'x' && ans[n - 1] == 'S' && ans[0] != ans[n - 2] ||
			str[n - 1] == 'o' && ans[n - 1] == 'W' && ans[0] != ans[n - 2] ||
			str[n - 1] == 'x' && ans[n - 1] == 'W' && ans[0] == ans[n - 2]);
}

int main() {
	
	cin >> n >> str;
	if (solve('S', 'S')) {
		cout << ans << endl;
	}
	else if (solve('S', 'W')) {
		cout << ans << endl;
	}
	else if (solve('W', 'S')) {
		cout << ans << endl;
	}
	else if (solve('W', 'W')) {
		cout << ans << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}