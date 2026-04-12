#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[310], R[101000], RC;
void Rotate(int K){
	R[RC++] = K;
	for (int i = K; i < n; i++)swap(w[i - K], w[i]);
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (w[0] < w[n - 1]) Rotate(n-1);
			Rotate(1);
		}
		for (j = 0; j < i - 1; j++)Rotate(1);
		if (i != n - 1)Rotate(1);
	}
	printf("%d\n", RC);
	for (i = 0; i < RC; i++)printf("%d\n", R[i]);
}