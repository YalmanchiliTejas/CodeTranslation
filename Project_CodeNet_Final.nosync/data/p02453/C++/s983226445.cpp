#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, q;

	cin >> n;
	vector<long long> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> q;

	for (int i = 0; i < q; i++) {
		long long k;
		cin >> k;

		cout << (lower_bound(a.begin(), a.end(), k) - a.begin()) << endl;
	}

	return 0;
}
