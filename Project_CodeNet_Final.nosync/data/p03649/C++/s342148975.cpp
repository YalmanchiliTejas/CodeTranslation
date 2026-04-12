#include <bits/stdc++.h>
using namespace std;
int n; long long a[55], ret;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	while(true) {
		int ptr = max_element(a, a + n) - a;
		if(a[ptr] < n) break;
		for(int j = 0; j < n; j++) {
			if(j != ptr) a[j] += a[ptr] / n;
		}
		ret += a[ptr] / n;
		a[ptr] %= n;
	}
	cout << ret << endl;
	return 0;
}