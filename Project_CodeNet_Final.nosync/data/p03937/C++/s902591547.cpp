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
# include <unordered_map>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int count = 0;
	for (int i = 0; i < h*w; i++) {
		char c;
		cin >> c;
		if (c == '#')count++;
	}
	cout << (count == h + w - 1 ? "Possible" : "Impossible") << endl;
}