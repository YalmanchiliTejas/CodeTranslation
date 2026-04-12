#include <iostream>
#include <algorithm>
#include <vector>


int my_abs(int a) {
	return a < 0 ? -a : a;
}


int main() {


	std::cin.tie(nullptr); std::ios::sync_with_stdio(false);
	int N; std::cin >> N;
	std::vector<int> H(N); for (int i = 0; i < H.size(); i++)std::cin >> H.at(i);
	bool flag = true;//見れる
	int ans = 1;
	
	for (int i = 1; i < H.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (H.at(j) > H.at(i)) {
				flag = false;
				break;
			}
			else {
				flag = true;
			}
		}
		if (flag)ans++;
	}

	std::cout << ans;

	return 0;


}