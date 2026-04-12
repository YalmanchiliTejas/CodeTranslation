#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, q, tmp;
	vector<int> A;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		A.push_back(tmp);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &tmp);
		printf("%d\n", distance(A.begin(), lower_bound(A.begin(), A.end(), tmp)));
	}
}
