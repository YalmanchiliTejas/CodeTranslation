#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int a,b,c,x,y;

	cin >> a >> b >> c >> x >> y;

	vector<int> cost;

	cost.push_back( a * x + b * y);
	
	if (x > y) {
		cost.push_back( a * (x - y) + 2 * c*y);
		cost.push_back( 2 * c*x);
	}
	else {
		cost.push_back( b * (y - x) + 2 * c*x);
		cost.push_back( 2 * c*y);
	}

	sort(cost.begin(), cost.end());
	cout << cost[0] << endl;



	return 0;
}