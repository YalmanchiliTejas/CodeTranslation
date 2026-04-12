#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1, -1);
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		int t = upper_bound(a.begin(), a.end(), b, comp) - a.begin();
		a[t] = b;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}