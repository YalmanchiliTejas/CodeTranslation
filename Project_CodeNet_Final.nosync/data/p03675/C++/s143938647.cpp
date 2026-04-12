#include <bits/stdc++.h> 

using namespace std;

deque <int> d;
int n, x;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		if (i & 1) d.push_back(x);
		else d.push_front(x);
	}
	if (n & 1) {
		for (int i = n - 1; i >= 0; --i) {
			printf("%d ", d[i]);
		} 
		puts("");
	} else {
		for (int i = 0; i < n; ++i) {
			printf("%d ", d[i]);
		} 
		puts("");
	}
  return 0;
}

