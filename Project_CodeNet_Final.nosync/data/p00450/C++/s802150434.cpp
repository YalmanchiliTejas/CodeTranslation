#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000000
int c[100005] = { 0 }, st[100005] = { 0 }, am[100005] = { 0 };
int n;
int main() {
	while (true) {
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			st[i] = am[i] = INF;
		}
		st[0] = c[0];
		am[0] = 1;
		int now = 0;
		for (int i = 1; i < n; i++) {
			if (i % 2) {
				if (st[now] == c[i]) {
					am[now]++;
				}
				else {
					if (now - 1 >= 0) {
						now--;
						am[now] += am[now + 1] + 1;
						st[now + 1] = am[now + 1] = INF;
					}
					else {
						if (st[now]) st[now] = 0;
						else st[now] = 1;
						am[now]++;
					}
				}
			}
			else {
				if (st[now] == c[i]) {
					am[now]++;
				}
				else {
					now++;
					st[now] = c[i];
					am[now] = 1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i <= now; i++) {
			if (st[i] == 0) res += am[i];
		}
		cout << res << endl;
	}
	return 0;
}
