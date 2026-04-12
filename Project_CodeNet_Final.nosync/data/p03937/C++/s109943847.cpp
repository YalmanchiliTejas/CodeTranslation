#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	scanf("%d %d", &H, &W);

	char a;
	scanf("%c", &a);  //改行文字空読み
	int pre_right = 0, right;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%c", &a);
			// printf("%c", a);
			if (a == '#') {
				right = j;
				// printf("pre = %d, now = %d\n", pre_right, right);
				if (pre_right > right) {
					printf("Impossible");
					return 0;
				}
			}
		}
		scanf("%c", &a);  //改行文字空読み

		pre_right = right;
	}
	printf("Possible");

	return 0;
}