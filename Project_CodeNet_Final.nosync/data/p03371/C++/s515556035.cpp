#include<bits/stdc++.h>

using namespace std;

int
main(void){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int tmp = min(x, y);
	int ans = min(x*a + y*b, min(tmp*2*c + (x - tmp)*a + (y - tmp)*b, max(x, y)* 2 * c));
	cout << ans; 
}