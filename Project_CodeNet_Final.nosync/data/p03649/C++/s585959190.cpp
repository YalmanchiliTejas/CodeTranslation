#include <iostream>
using namespace std;

int n;
long long a[50];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	long long ans = 0;
	
	for (int it = 0; it <= 2000; it++)
	for (int i = 0; i < n; i++) {
		long long cnt = a[i] / n;
		if (cnt != 0) {
			ans += cnt;
			a[i] %= n;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				a[j] += cnt;
			}
		}
	}
	cout << ans;
	
    return 0;
}
