#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = (x - z) / (y + z);
	cout << ans << endl;
	//x >= (y+z)*ans+z
}