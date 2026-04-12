#include <iostream>
using namespace std;

int n, l, r, a[50];

int main() {
	int i, j;
	
	while(cin >> n >> l >> r) {
		if (!n) break;
		for (i = 0; i < n; i++) cin >> a[i];
		
		int cnt = 0;
		for (i = l; i <= r; i++) {
			for (j = 0; j < n; j++) if (i % a[j] == 0) break;
			if (j % 2 == 0) { cnt++; }
		}
		cout << cnt << endl;
	}
	return 0;
}
