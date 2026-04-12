#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	int H[21];
	int height;
	int count;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	count = 0;
	height = 0;
	for (int i = 0; i < N; i++) {
		if (height <= H[i]) {
			count++;
			height = H[i];
		}
	}

	cout << count << endl;

	return 0;
}