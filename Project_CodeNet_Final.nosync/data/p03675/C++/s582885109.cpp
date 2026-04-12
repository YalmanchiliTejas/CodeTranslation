#include <bits/stdc++.h>
using namespace std;

int N, arr[200005];
bool rev;
deque<int> D;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		if (rev) D.push_front(arr[i]);
		else D.push_back(arr[i]);
		rev = !rev;
	}
	if (rev) {
		for (int i = D.size() - 1; i >= 0; i--) printf("%d ", D[i]);
		printf("\n");
	} else {
		for (int i = 0; i < D.size(); i++) printf("%d ", D[i]);
		printf("\n");
	}
}
