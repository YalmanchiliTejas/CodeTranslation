#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int i = 0;
	while (y * i + z * (i + 1) < x) {
		i++;
	}
	if (y * i + z * (i + 1) > x) {
		i--;
	}
	cout << i << endl;
	return 0;
}

