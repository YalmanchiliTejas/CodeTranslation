#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define int long long
signed main() {
	int a, b, ab; cin >> a >> b >> ab;
	ab = min(ab * 2, a + b);
	int x, y; cin >> x >> y;
	int k = min(x, y);
	x -= k; y -= k;
	cout << x * min(a,ab) + y * min(ab,b) + k * ab << endl;
}