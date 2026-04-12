#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iostream>
#include <deque>
#include <math.h>
#include <cstdio>
#include <functional>
#include <set>
#include <iomanip>
typedef  long long ll;
using namespace std;

int main(void) {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = a * x + b * y;
	for (ll i = 0; i < 100001; i++)
	{
		ll fee = i * 2 *c + max((ll)0,x - i) * a + max((ll)0, y - i) * b;
		ans = min(ans, fee);
	}
	cout << ans << endl;
	return 0;
}