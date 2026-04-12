#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> v;

//////////一般化した二分探索

const bool LEFT = false;
const bool RIGHT = true;
bool judgeLR(int i, int key);// 左に属するか右に属するかを判断する関数。下で定義する。

int nibutanL(int size, int key) {// LEFTグループに属するうち最も右側のindexを得る
	int L = -1;
	int R = size;
	while (abs(R - L) > 1) {
		int mid = (L + R) / 2;
		if (judgeLR(mid, key) == RIGHT) R = mid;
		else L = mid;
	}
	return L;
}
int nibutanR(int size, int key) {//RIGHTグループに属するうち最も左側のindexを得る
	return nibutanL(size, key) + 1;
}

bool judgeLR(int i, int key) {
	if (v[i] <= key) {
		return LEFT;
	}
	else {
		return RIGHT;
	}
}

int main() {
	int N; cin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	v.clear();
	for (int i = N - 1; i >= 0; i--) {
		int s = v.size();
		if (s == 0) {
			v.push_back(a[i]);
		}
		else if (a[i] >= v[s - 1]) {
			v.push_back(a[i]);
		}
		else {
			int n = nibutanR(s, a[i]);
			v[n] = a[i];
		}
	}

	cout << v.size() << endl;
	return 0;
}
