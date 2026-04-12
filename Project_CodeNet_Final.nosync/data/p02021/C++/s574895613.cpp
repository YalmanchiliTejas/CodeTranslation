#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n); std::vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int k = 100; k > 0; k--) {
		int tmp = 0;
		bool beet = true;
		for(int i = 0; i < n; i++) {
			tmp += a[i];
			if(tmp < k) {
				beet = false;
				break;
			}
			tmp -= k;
		}
		if(beet) {
			printf("%d\n", k);
			break;
		}
	}
	return 0;
}

