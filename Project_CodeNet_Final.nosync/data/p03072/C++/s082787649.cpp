#include<iostream>

int main() {
	int n, ans = 0;
	std::cin >> n;
	int *h = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (h[j] > h[i])flag = false;
		}
		ans += flag;
	}
	printf("%d\n",ans);
}