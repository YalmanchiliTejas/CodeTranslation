#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int count = 1;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H.at(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (H.at(i) < H.at(j)){
				break;
			}
			if (j == i - 1) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}