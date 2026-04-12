#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;



int main() {
	string s;
	cin >> s;

	char prev = ' ';

	for (char c : s) {
		if (prev == 'A' && c == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
		prev = c;
	}
	cout << "No" << endl;

	return 0;
}
