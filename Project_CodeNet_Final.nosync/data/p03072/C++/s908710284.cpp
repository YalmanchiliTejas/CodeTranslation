#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[20];
	int heightMax;
	int ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ans = 1;
	heightMax = a[0];

	for (int i = 1; i < n; i++) {
		if (heightMax <= a[i]) {
			ans++;
			heightMax = a[i];
		}
	}
	cout << ans << endl;
}