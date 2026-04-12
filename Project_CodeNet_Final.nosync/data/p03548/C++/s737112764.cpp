#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define debug(x) cerr << #x << "=" << x << endl;
#define lgx cerr << "-----------" << endl;

int main() {
	int x, y, z;
	while(cin >> x >> y >> z) {
		x -= z;
		int ans = x / (y+z);
		cout << ans << endl;
	}
	return 0;
}