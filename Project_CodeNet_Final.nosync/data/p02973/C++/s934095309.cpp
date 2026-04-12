#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m = 1;
int a[100000];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<pair<int, int>> c;
	c.push_back(make_pair(a[n - 1], 1));

	for (int i = n - 2; i >= 0; i--) {
		if (a[i] >= c.back().first) {
			m++;
			c.push_back(make_pair(a[i], m));
		}
		else {
			int j = 0;

			while (a[i] >= c[j].first)
				j++;

			c[j].first = a[i];

			while (j > 0 && c[j].first < c[j - 1].first) {
				swap(c[j], c[j - 1]);
				j--;
			}
		}
	}

	cout << m << endl;

	return 0;
}