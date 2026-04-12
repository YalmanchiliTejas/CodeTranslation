#include <iostream>
using namespace std;

int main() {
	int n;
	int ans = 0;
	int temp = 0;
	cin >> n;
	int *a = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (temp <= a[i]) {
			temp = a[i];
			ans++;
		}
	}
	cout << ans << endl;
}