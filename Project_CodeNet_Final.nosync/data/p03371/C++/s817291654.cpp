#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
int pra, prb, prc;
int x, y;
LL ans = 0;
int main()
{
	while (cin >> pra >> prb >> prc >> x >> y) {
		ans = 0;
		if (prc * 2 < pra + prb) {
			ans += min(x, y)*prc * 2;
			if (x > y)
				ans += (x - y)*pra;
			else ans += (y - x)*prb;
		} else {
			ans = x*pra + y*prb;
		}
		if (prc * 2 * max(x, y) < ans)
			ans = prc * 2 * max(x, y);
		cout << ans << endl;
	}
	return 0;
}