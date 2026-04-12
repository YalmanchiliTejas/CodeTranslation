#include <stdio.h>
char s[200];
int n, d, ans;
int x[100];
int y[100];
void solve1(void) {
	int i = 0;
	for (int j = 0; j < 100; j++) {
		if (y[j])i = j;
	}
	ans += y[i] + i * 9;
}
void solve2(void) {
	int i = 0;
	for (int j = 0; j < 100; j++) {
		if (y[j])i = j;
	}
	ans += 81 * i * (i - 1) / 2;
	ans += (y[i] - 1) * 9 * i;
	y[i] = 0;
	solve1();
}
void solve3(void){
	int i = 0;
	for (int j = 0; j < 100; j++) {
		if (y[j])i = j;
	}
	ans += 729 * i * (i - 1) * (i - 2) / 6;
	ans += (y[i] - 1) * 81 * i * (i - 1) / 2;
	y[i] = 0;
	solve2();
}
int main() {
	scanf(" %s", s);
	scanf("%d", &n);
	while (s[d] != NULL)d++;
	for (int i = 0; i < d; i++) {
		x[i + 100 - d] = s[i] - '0';
	}
	for (int i = 0; i < 100; i++) {
		y[i] = x[99 - i];
	}
	if (n == 3)solve3();
	if (n == 2)solve2();
	if (n == 1)solve1();
	printf("%d\n", ans);
}