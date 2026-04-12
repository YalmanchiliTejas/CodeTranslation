#include <stdio.h>
#include <string.h>

int n;
char S[11234][6];
int dice[6] = { 1,2,3,5,4,6 }, tmp = 0, ans = 0;

int main(void) {
	while (true) {
		ans = 0;
		dice[0] = 1;
		dice[1] = 2;
		dice[2] = 3;
		dice[3] = 5;
		dice[4] = 4;
		dice[5] = 6;
		scanf("%d", &n);
		if (n == 0) { break; }
		for (int i = 0; i < n; ++i) { scanf("%s", &S[i]); }

		for (int i = 0; i < n; ++i) {
			if (strcmp(S[i], "North") == 0) {
				tmp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
				ans += dice[0];
			}
			else if (strcmp(S[i], "East") == 0) {
				tmp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[2];
				dice[2] = tmp;
				ans += dice[0];
			}
			else if (strcmp(S[i], "South") == 0) {
				tmp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
				ans += dice[0];
			}
			else if (strcmp(S[i], "West") == 0) {
				tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[4];
				dice[4] = tmp;
				ans += dice[0];
			}
			else if (strcmp(S[i], "Right") == 0) {
				tmp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[3];
				dice[3] = dice[4];
				dice[4] = tmp;
				ans += dice[0];
			}
			else if (strcmp(S[i], "Left") == 0) {
				tmp = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[3];
				dice[3] = dice[2];
				dice[2] = tmp;
				ans += dice[0];
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}