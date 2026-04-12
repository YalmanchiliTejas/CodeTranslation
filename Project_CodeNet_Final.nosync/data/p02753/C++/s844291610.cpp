#pragma warning(disable: 4996)

#include <iostream>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <functional>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <numeric>
#include <string>
#include <set>
#include <tuple>
#include <utility>
#include <regex>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	bool ok = true;
	if (s == "AAA") ok = false;
	if (s == "BBB") ok = false;
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}