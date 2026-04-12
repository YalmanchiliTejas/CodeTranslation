#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, c, x, y,count=0;
	cin >> a >> b >> c >> x >> y;
	if ((a + b) / 2 >= c) {
		ll memo1 = min(x, y);
		count += c * memo1*2;
		if (x > y)count += (x - y)*min(a,c*2);
		else if (x < y)count += (y - x)*min(b,c*2);
	}
	else count += x * a + y * b;
	cout << count << endl;
	getchar();
	getchar();
	return 0;
}