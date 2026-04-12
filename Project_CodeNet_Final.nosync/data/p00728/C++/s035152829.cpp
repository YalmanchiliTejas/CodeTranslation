#include <iostream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

void solve(vector<int>& point)
{
	int total = point[0];
	int maxPoint = point[0];
	int minPoint = point[0];
	for(unsigned i=1; i<point.size(); ++i){
		total += point[i];
		maxPoint = max(maxPoint, point[i]);
		minPoint = min(minPoint, point[i]);
	}
	cout << ((total-maxPoint-minPoint)/(point.size()-2)) << endl;
}

int main()
{
	int number = 0;
	for(;;){
		int n;
		cin >> n;
		if(n == 0)
			break;

		vector<int> point(n);
		for(int i=0; i<n; ++i)
			cin >> point[i];

		solve(point);
	}

	return 0;
}