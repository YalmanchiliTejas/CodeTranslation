#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1;
		for (int j = i; j >= 0; j--) {
			if (h[i] < h[j]) {
				ans -= 1;
				break;
			}
		}
	}
	
	cout << ans << endl;
}