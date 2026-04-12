#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];
deque<int> q;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
	}

	for (int i = 0; i < n; ++i) {
		if ((i&1) == 0) q.push_back(a[i]);
		else q.push_front(a[i]);
	}

	while (!q.empty()) {
		if ((n&1) == 0) {
			printf("%d ", q.front());
			q.pop_front();
		} else { 
			printf("%d ", q.back());
			q.pop_back();
		}
	}
	return 0;
}
