#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << (((a * 100 + b * 10 + c) % 4) == 0 ? "YES" : "NO") << endl;

	return 0;
}