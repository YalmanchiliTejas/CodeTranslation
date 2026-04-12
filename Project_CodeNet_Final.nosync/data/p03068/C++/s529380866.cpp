//#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int n, k;
	char s[11];

	scanf("%d %s %d", &n, s, &k);
	char a = s[k-1];
	for (int i = 0; i < n; i++) {
		if (s[i] != a) {
			s[i] = '*';
		}
	}
	printf("%s", s);
}