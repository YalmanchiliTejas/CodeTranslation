#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
	for (;;) {
		int n;
		scanf("%d", &n);
		if (!n) break;

		int color, back_color = -1;
		stack<int> go;

		rep(i, n) {
			scanf("%d", &color);
			if (!(i % 2)) {
				if (color == back_color) {
					int c = go.top();
					go.pop();
					go.push(c + 1);
				}
				else {
					go.push(1);
					back_color = color;
				}
			}
			else {
				if (color == back_color) {
					int c = go.top();
					go.pop();
					go.push(c + 1);
				}
				else {
					int c = go.top();
					go.pop();
					if (!go.empty()) {
						c += go.top();
						go.pop();
					}
					go.push(c + 1);
					back_color = color;
				}
			}
		}

		if (back_color) {
			go.pop();
		}

		int count = 0;
		while (!go.empty()) {
			count += go.top();
			go.pop();
			if (!go.empty()) go.pop();
		}

		printf("%d\n", count);

	}
	return 0;
}