#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans =  x/(y + z);
	if (x % (y + z) < z) {
		ans--;
	}
	cout << ans;
}
