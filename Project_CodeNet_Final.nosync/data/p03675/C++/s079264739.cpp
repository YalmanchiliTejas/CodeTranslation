#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <queue>

using namespace std;

int n, x;
deque <int> q;

int main() {
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (n & 1)
			if (i & 1)
				q.push_back(x);
			else
				q.push_front(x);
		else
			if (i & 1)
				q.push_front(x);
			else
				q.push_back(x);
	}
	for (int i = 0; i < n; ++i)
		cout << q.front() << " ", q.pop_front();
	return 0;
}
