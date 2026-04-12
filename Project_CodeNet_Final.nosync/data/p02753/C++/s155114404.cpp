#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <cctype>
#include <climits>

using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;

using ll = long long int;

#define mp(a,b) make_pair(a,b)

const int MOD = 1000 * 1000 * 1000 + 7;

bool res() {
	string s;
	cin >> s;
	if (!cin) return false;

	if (s[0] == s[1] && s[1] == s[2]) cout << "No\n";
	else cout << "Yes\n";

	return true;
}

int main() {
	while (res()) {}
	return 0;
}