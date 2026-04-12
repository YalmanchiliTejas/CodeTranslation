#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	string ans = "No";
	if (30 <= x) {
		ans = "Yes";
	}
	cout << ans << endl;
	return 0;
}