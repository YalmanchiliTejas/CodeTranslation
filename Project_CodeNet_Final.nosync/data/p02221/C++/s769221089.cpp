#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;
typedef long long ll;

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}

int main() {
	int N; cin >> N;
	int size = 1 << N;

	vector<int>* v = new vector<int>[N];
	for (int i = 0; i < N; i++) {
		v[i].resize(size);
	}
	string S; cin >> S;
	vector<int> input(size);
	for (int i = 0; i < size; i++) {
		cin >> input[i];
	}
	int s = size;
	for (int n = 0; n < N; n++) {
		if (n == 0) {
			for (int i = 0; i < size; i += 2) {
				int j = i + 1;
				int x = input[i], y = input[j];
				if (x > y) { int c = x; x = y; y = c; }
				int c = y - x;
				if (S[c - 1] == '0') {
					v[0][i / 2] = x;
				}
				else {
					v[0][i / 2] = y;
				}
			}
			for (int i = 1; i < size; i += 2) {
				int j = (i + 1) % size;
				int x = input[i], y = input[j];
				if (x > y) { int c = x; x = y; y = c; }
				int c = y - x;
				if (S[c - 1] == '0') {
					v[0][i / 2 + size / 2] = x;
				}
				else {
					v[0][i / 2 + size / 2] = y;
				}
			}
		}
		else {
			s /= 2;
			for (int i0 = 0; i0 < size; i0 += s) {
				for (int i = i0; i < i0 + s; i+=2) {
					int j = i + 1;
					int x = v[n-1][i], y = v[n-1][j];
					if (x > y) { int c = x; x = y; y = c; }
					int c = y - x;
					if (S[c - 1] == '0') {
						v[n][i0 + (i - i0) / 2] = x;
					}
					else {
						v[n][i0 + (i - i0) / 2] = y;
					}
				}
				for (int i = i0 + 1; i < i0 + s; i += 2) {
					int j = i + 1;
					if (j == i0 + s) { j = i0; }
					int x = v[n - 1][i], y = v[n - 1][j];
					if (x > y) { int c = x; x = y; y = c; }
					int c = y - x;
					if (S[c - 1] == '0') {
						v[n][i0 + (i - i0) / 2 + s / 2] = x;
					}
					else {
						v[n][i0 + (i - i0) / 2 + s / 2] = y;
					}
				}
			}
		}
	}
	for (int i = 0; i < size; i++) {
		int k = i;
		int anchor = 0;
		int s = size;
		for (int n = 0; n < N; n++) {
			s /= 2;
			if (k & 1) {
				anchor += s;
			}
			k /= 2;
		}
		cout << v[N - 1][anchor] << endl;
	}

	return 0;
}
