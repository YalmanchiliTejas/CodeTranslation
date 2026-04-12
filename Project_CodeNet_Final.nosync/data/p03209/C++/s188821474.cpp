#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long llong;

llong burg_length[51];
llong burg_score[51];

void burg_init() {
	burg_length[0] = 1;
	burg_score[0] = 1;
	for (int i = 1; i <= 50; i++) {
		burg_length[i] = 2 * burg_length[i - 1] + 3;
		burg_score[i] = 2 * burg_score[i - 1] + 1;
	}
}


int main() {
	llong N, X;
	llong score = 0;
	burg_init();
	cin >> N >> X;

	for (int i = N; i >= 0; i--) {
		if (X == burg_length[i]) {
			score += burg_score[i];
			break;
		}
		else if (X == burg_length[i - 1] + 2) {
			score += burg_score[i - 1] + 1;
			break;
		}
		else if (X > burg_length[i - 1] + 2) {
			score += burg_score[i - 1] + 1;
			X -= burg_length[i - 1] + 2;
			continue;
		}
		else {
			X -= 1;
			continue;

		}
	}
	cout << score << endl;
	
	
	return 0;
}