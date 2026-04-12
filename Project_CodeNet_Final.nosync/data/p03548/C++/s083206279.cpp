#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	int ans = 0;
	ans += x / (y + z);
	if (x % (y + z) >= y + z) ans++;

	dunk(ans);

	return 0;
}