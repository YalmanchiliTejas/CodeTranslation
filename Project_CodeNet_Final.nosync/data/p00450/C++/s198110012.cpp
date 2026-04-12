#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

struct p {
	bool s;
	int count;
};

int n;

int main() {

	while (scanf("%d", &n), n != 0) {
		p rc[100000];
		bool C;
		int  c, t = -1, I = 0;

		memset(rc, 0, sizeof(rc));

		for (int i = 1; i <= n; i++) {
			scanf("%d", &c);
			if (c == 1) C = true;
			else C = false;

			if (c != t) {
				if (i % 2 == 0) {
					rc[I].s = C;
					rc[I].count++;
					if (rc[I].s == rc[I - 1].s && I != 1) {
						rc[I - 1].count += rc[I].count;
						rc[I].count = 0;
						I--;
					}
				}
				else {
					I++;
					rc[I].s = C;
					rc[I].count = 1;
				}
			}
			else rc[I].count++;
			t = c;
		}
		int ans = 0;
		for (int i = 1; i <= I; i++) {
			if (!rc[i].s) {
				ans += rc[i].count;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
