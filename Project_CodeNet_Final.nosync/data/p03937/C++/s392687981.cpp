/*
https://www.luogu.org/problem/AT2168
Author: Yu-343
*/

#include <cstdio>

int h, w, cnt = 0;
char ch;

int main (void) {
	scanf ("%d %d", &h, &w);
	for (int i = 1; i <= h; ++i) {
		getchar ();
		for (int j = 1; j <= w; ++j) {
			scanf ("%c", &ch);
			if (ch == '#') ++cnt;
		}
	}
	puts ((cnt == h + w - 1) ? "Possible" : "Impossible");
	return 0;
}