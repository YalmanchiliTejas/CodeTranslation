#include <iostream>
#include <string>
using namespace std;

int main() {
	string r, g, b;
	cin >> r >> g >> b;
	int n = stoi("" + r + g + b);
	string ans = "NO";
	if (n % 4 == 0) {
		ans = "YES";
	}
	cout << ans << endl;
	return 0;
}