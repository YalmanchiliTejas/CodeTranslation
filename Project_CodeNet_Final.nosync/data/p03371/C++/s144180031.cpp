#include <bits/stdc++.h>
using namespace std;

long long a, b, c, x, y;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> a >> b >> c >> x >> y;
	b = min(b, 2 * c);
	a = min(a, 2 * c);
	
	if(2 * c >= (a + b))
		return cout << 1LL * x * a + 1LL * y * b, 0;
	long long t = min(x, y);
	x -= t; y -= t;
	cout << 1LL * t * 2 * c + 1LL * x * a + 1LL * y * b;
}
