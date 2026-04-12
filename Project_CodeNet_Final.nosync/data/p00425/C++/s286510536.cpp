#include <stdio.h>

int main(void) {
	int n,m;
	char str[100];
	int open[7];
	int temp;
	int sum;

	while (scanf("%d", &n), n) {
		for (int i = 1; i < 7; i++)open[i] = i;
		sum = 1;
		while (n--) {
			scanf("%s", str);
			if (str[0] == 'N') {
				temp = open[1];
				open[1] = open[2];
				open[2] = open[6];
				open[6] = open[5];
				open[5] = temp;
			}
			else if (str[0] == 'S') {
				temp = open[1];
				open[1] = open[5];
				open[5] = open[6];
				open[6] = open[2];
				open[2] = temp;
			}
			else if (str[0] == 'E') {
				temp = open[1];
				open[1] = open[4];
				open[4] = open[6];
				open[6] = open[3];
				open[3] = temp;
			}
			else if (str[0] == 'W') {
				temp = open[1];
				open[1] = open[3];
				open[3] = open[6];
				open[6] = open[4];
				open[4] = temp;
			}
			else if (str[0] == 'R') {
				temp = open[2];
				open[2] = open[3];
				open[3] = open[5];
				open[5] = open[4];
				open[4] = temp;
			}
			else if (str[0] == 'L') {
				temp = open[2];
				open[2] = open[4];
				open[4] = open[5];
				open[5] = open[3];
				open[3] = temp;
			}
			sum += open[1];
		}
		printf("%d\n", sum);
	}
	return 0;
}