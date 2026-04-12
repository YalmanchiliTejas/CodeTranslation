#include <iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int N;
	int H[200];
	int count = 0;//見れる山カウント
	int max_height=0;
	int height = 0;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}

	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			max_height = H[i];
				++count;
		}
		else if (max_height <= H[i]) {
			max_height = H[i];
			++count;
		}
	}




	cout << count;
}
