#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
	cin >> N;
	vector<int> height(N);
	for (int i = 0; i < N; i++) {
		cin >> height.at(i);
	}

	int CanSee = 1;

	for (int i = 1; i < N; i++) {
		bool check = true;
		for (int j = 0; j < i; j++) {
			if (height.at(i) < height.at(j)) {
				check = false;
				break;
			}
		}
		if (check) {
			CanSee++;
		}
	}
	cout << CanSee << endl;

}