#include<bits/stdc++.h>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	int cnt = 0;
	while (x >= y + z) {
		cnt++;
		x -= (y + z);
	}
	cout << cnt;
}