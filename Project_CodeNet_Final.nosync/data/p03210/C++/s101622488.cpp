#include <iostream>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
signed main() {
	int x; cin >> x;
	if (x % 2 == 1) {
		x--;
		cout << (x&&x <= 6 ? "YES\n" : "NO\n");
	}
	else cout << "NO\n";
}