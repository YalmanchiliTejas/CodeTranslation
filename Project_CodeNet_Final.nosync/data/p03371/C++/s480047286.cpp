
#include <bits/stdc++.h>
#include <vector>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

using namespace std;

int main() {

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll ans = 0;
	ll hoge = 0;

	if (c*2 < a + b) { // c買ったほうが得

		hoge = min(x, y);
		ans += c * hoge * 2;

		hoge = max(x, y) - min(x, y);
		if (x == max(x, y)) ans += a * hoge;
		else ans += b * hoge;

		if (ans > max(x, y)*2*c) ans = max(x, y)*2*c;

	} else {

		ans += a * x + b * y;
	}

	cout << ans << endl;
}

//printf("%ld\n", ans);