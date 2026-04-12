#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define MAX 100000
#define INF 2140000000
#define MOD 1000000007

int main() {
	string s;
	cin >> s;

	set<char> ss;

	for (int i = 0; i < (int) s.size(); ++i) {
		ss.insert(s[i]);
	}

	if ((int) ss.size() == 2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}