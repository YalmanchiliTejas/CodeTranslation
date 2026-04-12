# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
using namespace std;
using LL = long long;
constexpr int MOD = 1000000000 + 7;
//?¶????????????????????????????????????§??????????????????????¢????????????????
constexpr int INF = 2000000000;
const double PI = acos(-1);

int use_hands(char c) {
	if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' ||
		c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' ||
		c == 'z' || c == 'x' || c == 'c' || c == 'v' || c == 'b')return 1;
	else return 0;
}

int main() {
	string s;
	while (cin >> s&&s != "#") {
		int ans = 0;
		for (int i = 1; i < s.size(); i++) {
			if (use_hands(s[i]) != use_hands(s[i - 1]))ans++;
		}
		cout << ans << endl;
	}
}