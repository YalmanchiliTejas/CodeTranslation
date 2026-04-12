#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;


int main()
{
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int mi = std::min(x, y);

	ll s1 = a * mi + b * mi;
	ll s2 = c * 2 * mi;

	ll ans = std::min(s1, s2);

	if (y-mi>0) {
		ll ss1 = b * (y-mi);
		ll ss2 = c * 2 * (y-mi);
		ans += std::min(ss1, ss2);
	} else if (x-mi>0) {
		ll ss1 = a * (x-mi);
		ll ss2 = c * 2 * (x-mi);
		ans += std::min(ss1, ss2);
	}
	cout << ans << endl;
}
