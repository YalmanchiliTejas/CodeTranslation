#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, hMax = 0, num = 0;
	cin >> n;
	vector<int> ls(n);
	for_each(ls.begin(), ls.end(), [](int& x) {cin >> x; });

	for_each(ls.begin(), ls.end(), [&](int& h) {
		if (h >= hMax) {
			++num;
			hMax = h;
		}
		});
	cout << num << endl;

	return 0;
}