#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int mn = 1001001001;
	if(x < y){
		swap(x, y);
		swap(a, b);
	}
	int cost = 0;
	// case 1
	cost = a * x + b * y;
	mn = min(mn, cost);
	// case 2
	cost = y * c * 2 + (x - y) * a;
	mn = min(mn, cost);
	// case 3
	cost = x * c * 2;
	mn = min(mn, cost);
	cout << mn << endl;
	return 0;
}