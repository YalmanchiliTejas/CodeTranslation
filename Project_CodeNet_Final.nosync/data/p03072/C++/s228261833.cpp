#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> H;
	int i, j;
	for (i = 0; i < N; i++) {
		int h;
		cin >> h;
		H.push_back(h);
	}
	int ans = 0;
	for (i = 0; i < N; i++) {
		bool b = true;
		for (j = 0; j < i; j++) {
			if (H.at(i) < H.at(j)) {
				b = false;
				break;
			}
		}
		if (b == true) {
			ans++;
		}
	}
	cout << ans;
}