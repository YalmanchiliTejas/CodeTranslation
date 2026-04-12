#include <bits/stdc++.h>


using namespace std;

int main() {

	int a, b, c, x, y, res, res1, res2, mini;
	cin >> a >> b >> c >> x >> y;
	
	mini = min(x, y);
	res = (max(x,y) * 2 * c);
	res1 = a*x + b*y ;
	res2 = mini * 2 * c;
	x -= mini;
	y -= mini;
	res2 += x*a + y*b;
	cout << min(res, min(res1, res2));

	return 0;
}