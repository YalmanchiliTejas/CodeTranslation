#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 2e5;
int n, a[MaxN + 5];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n & 1) {
		for (int i = n; i >= 1; i -= 2) printf("%d ", a[i]);
		for (int i = 2; i <= n - 1; i += 2) printf("%d ", a[i]);
		printf("\n");
	}
	else {
		for (int i = n; i >= 2; i -= 2) printf("%d ", a[i]);
		for (int i = 1; i <= n - 1; i += 2) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}