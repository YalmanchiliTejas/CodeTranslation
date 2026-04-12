#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int max = h[0];
	for (int i = 1; i <= n - 1; i++) {
		if (max <= h[i] && h[i - 1] <= h[i]) {
			max = h[i];
			ans++;
		}

	}
	cout << ans << endl;
}