#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	printf("%d\n", 800 * N - 200 * (N / 15));

	return 0;
}
