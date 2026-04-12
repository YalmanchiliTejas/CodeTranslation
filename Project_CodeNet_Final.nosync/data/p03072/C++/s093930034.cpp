#include<iostream>

using namespace std;

int main(void) {
	int n;
	int m = 0;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp >= m) {
			ans++;
			m = tmp;
		}
	}
	cout << ans;
	
	return 0;
}