#include<iostream>
#include<vector>

int main() {
	int n,k=1,count=1;
	std::cin >> n;

	std::vector<int> v(n);
	for (int& x : v) {
		std::cin >> x;
	}

	for (int i = 1; i < n ; i++) {
		k = 0;
		for (int j = 0; j < i;j++) {
			if (v[j] > v[i]) {
				continue;
			}
			else {
				k++;

				if (i == k) {
					count++;
				}
			}
		}

	}

	std::cout << count << std::endl;
	return 0;
}