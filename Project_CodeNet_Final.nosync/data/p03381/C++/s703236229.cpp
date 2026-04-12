#include <bits/stdc++.h>
using namespace std;

int N;
int X[1<<18], s[1<<18];

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", X+i);
		s[i] = X[i];
	}

	sort(s, s + N);
	for (int i = 0; i < N; ++i) {
		int a = s[(N+1)/2-1], b = s[(N+1)/2];
		printf("%d\n", X[i] >= b ? a : b);
	}
}