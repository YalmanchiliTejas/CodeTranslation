#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	c *= 2;
	if(x > y) {
		swap(x, y);
		swap(a, b);
	}
	int p1 = y * c;
	int p2 = x * c + (y - x) * b;
	int p3 = x * a + y * b;
	cout << min({p1, p2, p3}) << endl; 
	return 0;	
}