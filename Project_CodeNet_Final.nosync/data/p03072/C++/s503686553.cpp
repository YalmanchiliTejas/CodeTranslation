#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <limits>
#include <iterator>
#include <cmath>
#include <numeric>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> h(n); for (int i = 0;i < n;i++) { cin >> h[i]; }
	int ans = 1;
	int big = h[0];
	auto iter = h.begin() + 1;
	while (iter != h.end())
	{
		if (big <= *(iter))
		{
			ans++;
			big = *(iter);
		}
		iter++;
	}
	cout << ans << endl;
	return 0;
}