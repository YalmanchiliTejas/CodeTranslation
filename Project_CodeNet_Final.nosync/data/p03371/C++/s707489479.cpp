#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	vector<long long> ans;
	ans.push_back(a*x + b*y);
	ans.push_back(2*c*(x < y ? y : x));
	ans.push_back((2*c*(x < y ? x : y)) + (x < y ? (y - x)*b : (x - y)*a));
	
	cout << *min_element(ans.begin(), ans.end()) << endl;
	
	return 0;
}