
#include <stdio.h>
#include <iostream>
using namespace std;

int a[100001];
int L[100000];

int main()
{
	int ret;
	int N;
	int len;

	ret = scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		ret = scanf("%d", &(a[i]));
	}

	len = 0;
	for (int i = 1; i <= N; i++) {
		int val = a[i];

		//len-1～0までループ j
		int j;
		j = len - 1;
		for (; j >= 0; j--) {
			if (L[j] >= val) break;
		}
		int idx = j + 1;

		L[idx] = val;
		if (idx == len) len++;
	}

	printf("%d", len);

	return 0;
}
