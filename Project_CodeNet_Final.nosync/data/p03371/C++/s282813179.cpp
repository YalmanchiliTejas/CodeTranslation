#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<iomanip>
#define FAST ios::sync_with_stdio(false)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 9;
const int maxn = (int)1e5 + 5;
using namespace std;

int a[105];

int main()
{
	FAST;
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans;
	if(x == 0){
		ans = min(b, 2 * c) * y;
		return cout << ans << endl, 0;
	}
	if(y == 0){
		ans = min(a, 2 * c) * y;
		return cout << ans << endl, 0;
	}
	ans = min(a + b, 2 * c) * min(x, y);
	if(x > y){
		if(a <= 2 * c)
			ans += ((x - y) * a);
		else ans += (2 * c * (x - y));
	}
	if(x < y){
		if(b <= 2 * c)
			ans += ((y - x) * b);
		else ans += ((y - x) * 2 * c);
	}
	cout << ans << endl;
	return 0;
}