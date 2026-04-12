#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	char c1, c2, c3; cin >> c1 >> c2 >> c3;
	cout << (c1 != c2 || c2 != c3 ? "Yes" : "No") << '\n';
	return 0;
}
