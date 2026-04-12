#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int cnt = 1;
	int max = h[0];
	for (int i = 1; i < n; i++) {
		if (max <= h[i]) {
			max = h[i];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}