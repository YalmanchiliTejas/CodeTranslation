#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int h[20];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int max_height = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (max_height <= h[i]) {
			count++;
		}

		max_height = std::max(max_height, h[i]);
	}

	cout << count << endl;

	return 0;
}
