#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int a[25] = {};

int main() {
	int n;
	int ans = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[0]) {
			continue;
		}
		int num = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] >= a[j]) {
				num++;
			}
		}

		if (i == num) {
			ans++;
		}
	}

	cout << ans << endl;


}
