#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans;
	int yen;
	
	// ABピザをmin(x, y)枚買い、残りはAピザorBピザを買う
	int tmp_x = x, tmp_y = y;
	yen = c * 2 * min(x, y);
	tmp_x -= min(x, y);
	tmp_y -= min(x, y);
	if(tmp_x > 0) yen += a * tmp_x;
	if(tmp_y > 0) yen += b * tmp_y;
	ans = yen;
	
	// ABピザをmax(x, y)枚買う
	yen = c * 2 * max(x, y);
	ans = min(ans, yen);
	
	//AピザとBピザのみを買う
	yen = a * x + b * y;
	ans = min(ans, yen);
	
	cout << ans << endl;
	
	return 0;
}