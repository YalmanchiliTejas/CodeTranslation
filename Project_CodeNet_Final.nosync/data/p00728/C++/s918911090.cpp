#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100

int n, s[MAX];

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			return 0;

		for(int i = 0; i < n; i++)
			scanf("%d", s + i);
		sort(s, s + n);

		int ans = 0;
		for(int i = 1; i < n - 1; i++)
			ans += s[i];

		printf("%d\n", ans / (n - 2));
	}
}