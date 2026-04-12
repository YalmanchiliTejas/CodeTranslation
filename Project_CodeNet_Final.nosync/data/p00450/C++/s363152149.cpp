#include <stack>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int Q, x, s1[100009], s2[100009];
int main() {
	while (scanf("%d", &Q), Q) {
		int l = 0;
		for (int i = 1; i <= Q; i++) {
			scanf("%d", &x);
			if (i & 1) {
				if (l == 0 || x != s1[l - 1]) s1[l] = x, s2[l++] = 1;
				else s2[l - 1]++;
			}
			else {
				if (x == s1[l - 1]) s2[l - 1]++;
				else {
					if (l == 1) s1[l - 1] ^= 1, s2[l - 1]++;
					else s2[l - 2] += s2[l - 1] + 1, l--;
				}
			}
		}
		int ret = 0;
		for (int i = 0; i < l; i++) {
			if (s1[i] == 0) ret += s2[i];
		}
		printf("%d\n", ret);
	}
	return 0;
}