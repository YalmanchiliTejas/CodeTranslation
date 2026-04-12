#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
	int n, a;
	deque<int> B;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i & 0x1)
			B.push_front(a);
		else
			B.push_back(a);
	}
	if (n & 0x1) {
		printf("%d", B[n - 1]);
		for (int i = n - 2; 0 <= i; i--)
			printf(" %d", B[i]);
		printf("\n");
	} else {
		printf("%d", B[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", B[i]);
		printf("\n");
	}
}