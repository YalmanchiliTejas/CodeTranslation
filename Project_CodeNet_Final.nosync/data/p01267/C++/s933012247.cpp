#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>

using namespace std;

#define Getsign(n) ((n > 0) - (n < 0))
#define QWERTYR(c) (c == 'y' || c == 'u' || (c >= 'h' && c <= 'p') ?	true : false)
typedef vector<int> Ivec;
typedef pair<int, int> Pos;

int main() {
	int n, a, b, c, x;
	while (scanf("%d %d %d %d %d", &n, &a, &b, &c, &x)) {
		if (!n)
			return 0;
		queue<int> ransus;

		for (int i = 0; n > i; i++) {
			int a;
			scanf("%d", &a);
			ransus.push(a);
		}
		int i;
		bool f = false;
		for (i = 0; 10000 >= i; i++) {
			if (ransus.front() == x) {
				ransus.pop();
				if (ransus.empty()) {
					f = true;
					break;
				}
			}
			x = (a*x + b) % c;
		}
		if (f)
			printf("%d\n", i);
		else
			printf("-1\n");
	}



	return 0;
}