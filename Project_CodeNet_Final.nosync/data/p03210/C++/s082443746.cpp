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

	int x;
	cin >> x;

	if (x == 3 || x == 5 || x == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}