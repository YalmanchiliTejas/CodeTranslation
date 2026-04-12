#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++) 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, g, b;
	cin >> r >> g >> b;
	int sum = r * 100 + g * 10 + b;
	if (sum % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}