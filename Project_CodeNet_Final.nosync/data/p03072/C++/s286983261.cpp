#include <iostream>

using namespace std;


int main () {
	int n, h[101], cnt = 0, tmp = -1;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (tmp <= h[i]) {
			cnt++;
			tmp = h[i];
		}
	}

	cout << cnt;


}