#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	long long heights;
	long long max = -1;
	long long sum=0;

	scanf("%d", &N);
	for (int _ = 0; _ < N; _++) {
		scanf("%lld", &heights);
		if (heights >= max || max==-1) {
			max = heights;
			sum++;
		}
	}

	printf("%lld", sum);
}