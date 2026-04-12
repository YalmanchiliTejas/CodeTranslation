#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;

	int x = 800 * n;
	int get = n / 15;
	int y = 200 * get;

	cout << x - y << endl;
}