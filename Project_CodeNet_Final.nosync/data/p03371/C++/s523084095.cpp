#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)

int a, b, c, x, y;
int main()
{
	cin >> a >> b >> c >> x >> y;

	int ans = 0;
	if (x <= y) {
		if (a + b <= 2 * c) {
			ans += (x * (a + b));
		}
		else {
			ans += (x * 2 * c);
		}

		ans += min((y - x)*b, (y - x) * 2 * c);
	}
	else {
		if (a + b <= 2 * c) {
			ans += (y * (a + b));
		}
		else {
			ans += (y * 2 * c);
		}

		ans += min((x - y)*a, (x - y) * 2 * c);
	}
	cout << ans << endl;
	return 0;
}