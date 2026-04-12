#include <cstdio>
using namespace std;

int main() {
	int n;
	int h[105];
	scanf("%d", &n);
	int max = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		if (h[i] >= max) {
			max = h[i];
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}