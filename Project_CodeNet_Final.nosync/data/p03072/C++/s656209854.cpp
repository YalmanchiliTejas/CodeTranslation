#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	vector<int> height(N);
	for (int i = 0; i < N; i++) {
		cin >> height.at(i);
	}
	

	for (int i = 0; i < N; i++) {
		bool loop = true;
		for (int j = 0; j < i; j++) {
			if (height.at(j) > height.at(i)) {
				loop = false;
			}
		}
		if (loop) {
			count++;
		}
	}
	cout << count << endl;
}

