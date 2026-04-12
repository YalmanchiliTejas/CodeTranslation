#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int k, n;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;

	for (int i = 0; i < n; i++) {
		if (s[i] != s[k-1]) {
			s[i] = '*';
		}
	}

	cout << s << endl;

	return 0;
}