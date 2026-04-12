#include <bits/stdc++.h>

using namespace std;

int main(){
	int a ,b ,c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans1, ans2 , ans3;
	bool c_is_optimal = false;
	ans1 = min(x,y) * c * 2;
	int t = min(x,y);
	ans1 += (x - t)*a + (y - t)*b;
	ans2 = a * x + b * y;
	ans3 = max(x,y) *c * 2;
	cout << min(min(ans1,ans2),ans3);
}
	