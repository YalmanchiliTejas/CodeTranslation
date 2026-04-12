#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 19];
int B[1 << 18], L;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		int pos1 = lower_bound(B, B + L, -A[i] + 1) - B;
		B[pos1] = -A[i];
		if (pos1 == L) { L++; }
	}
	cout << L << endl;
	return 0;
}