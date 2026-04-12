#include <iostream>

using namespace std;
int main()
{
	int n, a[128], h = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; cin >> a[i], i++);
	for (int i = 0; i < n; i++) {
		if (a[i] >= h) {
			h = a[i];
			++m;
		}
	}
	cout << m;
	return 0;
}