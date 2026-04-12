#include <iostream>
using namespace std;

int main() {
	string ans;
	int r, g,b;
	cin >> r >> g>>b;
	r = r*100;
	g = g * 10;
	int rgb;
	rgb = r + g + b;
	if (rgb%4==0) {
		ans = "YES";
	}
	else {
		ans = "NO";
	}
	cout << ans << endl;
	return 0;
}
