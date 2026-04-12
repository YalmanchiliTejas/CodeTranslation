#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

	std::cin.tie(nullptr); std::ios::sync_with_stdio(false);

	int r, g, b; cin >> r >> g >> b;

	if ((g * 10 + b) % 4 == 0)cout << "YES";
	else cout << "NO";

	return 0;

}