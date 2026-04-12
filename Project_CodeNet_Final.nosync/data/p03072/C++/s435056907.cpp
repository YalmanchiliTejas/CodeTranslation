#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, h, mx = 0, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (h >= mx) {
			ans++;
			mx = h;
		}
	}
	cout << ans << endl;
}