#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	int x, y, z;
	cin >> x >> y >> z;
	int n = 0;
	for (n; n*(y + z) + z <= x; n++) {
	}
	cout << n - 1;
	return 0;
}