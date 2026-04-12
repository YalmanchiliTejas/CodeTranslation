#include <bits/stdc++.h>
using namespace std;
#define N_MAX 100000
int X[N_MAX];
int N, Q;

void swap(int a, int b) {
	int tmp = X[a];
	X[a] = X[b];
	X[b] = tmp;
	return;
}

void move(int cur) {
	if(0 < cur && X[cur - 1] == 0) X[cur - 1] = 1;
	if(cur < N - 1 && X[cur + 1] == 0) X[cur + 1] = 1;
	return;
}

int main() {
	cin >> N >> Q;
	for(int i = 0; i < N_MAX; i++) {
		X[i] = 0;
	}
	int cur = 0;
	int A, B;
	X[0] = X[1] = 1;
	for(int i = 0; i < Q; i++) {
		cin >> A >> B;
		A--, B--;
		if(A == cur) cur = B;
		else if(B == cur) cur = A;
		swap(A, B);
		move(cur);
	}
	move(cur);
	int S = 0;
	for(int i = 0; i < N; i++) {
		S += X[i];
	}
	cout << S << endl;
	return 0;
}