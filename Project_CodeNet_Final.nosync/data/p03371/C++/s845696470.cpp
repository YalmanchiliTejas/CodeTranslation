#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;


int main() {
	int a, b, c, x, y;
	int cost;
	int min_cost = INT_MAX;
	cin >> a >> b >> c >> x >> y;
	for (int i = 0;i <= max(x, y);i++) {
		cost = 2 * i * c + a * max(0, x - i) + b * max(0, y - i);
		min_cost = min(cost, min_cost);
	}
	cout << min_cost << endl;
}
