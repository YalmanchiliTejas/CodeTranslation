#include<bits/stdc++.h>

using lint = long long int;
using pii = std::pair<int, int>;

using std::vector;
using std::deque;

deque<int> de;

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		if ((N - i) % 2 == 0) {
			de.push_front(temp);
		}
		else {
			de.push_back(temp);
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", de.front());
		de.pop_front();
	}

	return 0;
}