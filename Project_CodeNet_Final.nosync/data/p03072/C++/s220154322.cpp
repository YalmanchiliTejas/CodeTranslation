#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int H[20];
	int ans = 0;
	int HMax = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
		if (H[i] >= HMax) ans++;
		HMax = max(HMax, H[i]);
	}

	printf("%d\n", ans);
	return 0;
}
