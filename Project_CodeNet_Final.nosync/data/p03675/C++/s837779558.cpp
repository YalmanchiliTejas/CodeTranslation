#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, Odd[100010], Even[100010];
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			cin >> Odd[i / 2];
		}
		else {
			cin >> Even[i / 2];
		}
	}
	if (N % 2 == 0) {
		for (int i = N / 2 - 1; i >= 0; i--) {
			cout << Even[i] << " ";
		}
		for (int i = 0; i < N / 2; i++) {
			cout << Odd[i];
			if (i != N / 2 - 1) cout << " ";
		}
	}
	else {
		for (int i = N / 2; i >= 0; i--) {
			cout << Odd[i] << " ";
		}
		for (int i = 0; i < N / 2; i++) {
			cout << Even[i];
			if (i != N / 2 - 1) cout << " ";
		}
	}
}