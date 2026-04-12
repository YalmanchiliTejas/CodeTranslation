#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
int main() {
	int n, m, o, x, y;
	cin >> n >> m >> o >> x >> y;
	int X = n * x + m * y;
	int Y = o * min(x, y) * 2 + (x - min(x, y))*n + (y - min(x, y))*m;
	int Z = o * max(x, y) * 2;
	cout << min({ X,Y,Z }) << endl;
	return 0;
}