#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;
const int INF = 2000000005;
int main()
{
	int a, b, c, x, y, ans = 0;
	cin >> a >> b >> c >> x >> y;
	if (a + b > c * 2) {
		ans += c * 2 * min(x, y);
		int p1 = (max(x, y) - min(x, y)) * 2 * c;
		int p2s;
		if (x > y) p2s = a;
		else p2s = b;
		int p2 = (max(x, y) - min(x, y))*p2s;
		ans += min(p1, p2);
	}
	else {
		ans = a*x + b*y;
	}
	cout << ans << endl;
	return 0;
}