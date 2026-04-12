#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main () {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri() / 10;
	
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (i > max) break;
		max = std::max(max, i + a[i]);
	}
	if (max < n - 1) {
		std::cout << "no" << std::endl;
		return 0;
	}
	int min = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (i < min) break;
		min = std::min(min, i - a[i]);
	}
	std::cout << (min <= 0 ? "yes" : "no") << std::endl;
	return 0;
}

