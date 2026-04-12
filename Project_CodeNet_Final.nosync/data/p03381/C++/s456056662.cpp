#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>

using namespace std;

/*
真ん中の二つをa, b (a<=b)とする。
X_i <= aであれば中央値はb、
X_i >= bであれば中央値はaである。

*/
int N;
int A[200000];
int B[200000];
int a, b;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	sort(B, B + N);
	a = B[N / 2 - 1];
	b = B[N / 2];
	for (int i = 0; i < N; i++) {
		if (A[i] <= a) { printf("%d\n", b); }
		else { printf("%d\n", a); }
	}

}