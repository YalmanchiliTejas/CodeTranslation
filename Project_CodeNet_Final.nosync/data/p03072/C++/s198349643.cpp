#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, H, MAX, count = 1;
	cin >> N >> MAX;
	for (int i = 1; i < N; i++) {
		cin >> H;
		if (MAX <= H) {
			count++;
			MAX = H;
		}
	}
	cout << count << endl;
}