#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main() {
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0;
	if(c * 2 <= a + b) {
		ans += 2 * c * min(x,y);
		x -= ans / 2 / c;
		y -= ans / 2 / c;
	}
	if(c * 2 <= a) {
		int tmp = x;
		ans += 2 * c * tmp;
		x -= tmp;
		x = max(x,0);
		y -= tmp;
		y = max(y,0);
	}
	if(c * 2 <= b) {
		int tmp = y;
		ans += 2 * c * tmp;
		x -= tmp;
		x = max(x,0);
		y -= tmp;
		y = max(y,0);
	}

	ans += x * a;
	ans += y * b;

	cout << ans << endl;



}
