#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int max;
	cin >> max;
	int ret = 1;
	for (int i = 1; i < n; ++i) {
		int h;
		cin >> h;
		if (max <= h) {
			++ret;
			max = h;
		}
	}

	cout << ret << endl;

	return 0;
}