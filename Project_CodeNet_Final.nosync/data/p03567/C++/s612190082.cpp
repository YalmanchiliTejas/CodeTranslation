#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

signed main() {
	string s;
	cin >> s;
	
	for (int i = 0; i < (int)s.length() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	return 0;
}