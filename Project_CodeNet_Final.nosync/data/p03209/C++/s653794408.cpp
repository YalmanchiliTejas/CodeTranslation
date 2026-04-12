#include <iostream>
#include <vector>

const int N_MAX = 50;

int main() {
	long long N, X;
	std::cin >> N >> X;

	// numPate[i] iレベルが含むパティの数
	std::vector<long long> numPate(N_MAX + 1);
	std::vector<long long> numLayer(N_MAX + 1);
	long long pate = 1;
	long long layer = 1;
	for(int i = 0; i <= N_MAX; i++) {
		numPate[i] = pate;
		numLayer[i] = layer;
		pate = pate * 2 + 1;
		layer = layer * 2 + 3;
	}

	long long result = 0;
	for(int i = N; i >= 0; i--) {
		if(X == 0) {
			break;
		} else if(i == 0) {
			// 0レベルは別
			if(X == 1) {
				result += 1;
				X -= 1;
			}
		} else if(X == numLayer[i]) {
			// 最後のパンズまで
			result += numPate[i];
			X -= numLayer[i];
		} else if(X >= (numLayer[i - 1] + 2)) {
			// 真ん中のパティ以上
			result += numPate[i - 1] + 1;
			X -= numLayer[i - 1] + 2;
		} else {
			X -= 1;
		}
	}

	std::cout << result << std::endl;

	return 0;
}