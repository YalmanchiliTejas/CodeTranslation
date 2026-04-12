#include <map>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[200009];
int main() {
	scanf("%d", &n);
	map<long long, int> d;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		d[sum] = i + 1;
	}
	int ret = 0; long long sum2 = 0;
	for (int i = 0; i < n; i++) {
		if (d[sum2] > i) ret = max(ret, d[sum2] - i);
		sum2 += a[i];
	}
	printf("%d\n", ret);
	return 0;
}