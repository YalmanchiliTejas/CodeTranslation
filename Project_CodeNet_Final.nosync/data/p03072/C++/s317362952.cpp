#include <iostream>
using namespace std;
#define ll long long

int main() {
	ll n, h[30], ans, k;
	ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> h[i];
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = 0; j < i; j++) {
			if (h[j] <= h[i])k++;
		}
		if (i == k)ans++;
	}
	cout << ans << endl;
}