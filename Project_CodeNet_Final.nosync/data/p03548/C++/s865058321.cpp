#include <iostream>

using namespace std;

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int ans, f = 0, p = 0, d;
	while (f == 0) {
		p++;
		d = X - Y*p - Z*(p+1);
		if (d < 0) {
			ans = p - 1;
			goto l1;
		}
	}
l1:	cout << ans << endl;
	return 0;
}