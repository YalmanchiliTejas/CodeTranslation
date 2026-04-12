#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;



int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	c *= 2;
	if (c == min(min(a, b), c)) cout << max(x, y) * c;
	else if (c < a)cout << x * c + max(0, y - x) * b;
	else if (c < b)cout << y * c + max(0, x - y) * a;
	else if (a + b < c)cout << x * a + y * b;
	else if (x > y) cout << y * c + (x - y) * a;
	else cout << x * c + (y - x) * b;
}