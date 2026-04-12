#include <iostream>

int main()
{
	int n;
	int h,m,ans;
	ans = 0;
	std::cin >> n;
	m = -1;
	for (int i = 0; i < n; i++) {
		std::cin >> h;
		if (h >= m) {
			m = h;
			ans++;
		}
	}
	std::cout << ans;
}