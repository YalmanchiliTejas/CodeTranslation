#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 800 * n;
	int count = n / 15;
	ans -= 200 * count;
	cout << ans << endl;
	return 0;
}