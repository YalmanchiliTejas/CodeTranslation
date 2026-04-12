#include <bits/stdc++.h>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int r,g,b;
	cin >> r >> g >> b;

	if (((r * 100) + (g * 10) + b) % 4 == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}