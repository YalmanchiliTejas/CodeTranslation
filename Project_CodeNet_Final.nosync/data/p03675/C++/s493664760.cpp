#include <bits/stdc++.h>
using namespace std;

int main () {
	
	int n=0, v=0, c=1, i=0;
	deque <int> dq;

	scanf("%d", &n);

	scanf("%d", &v);
	dq.push_back(v);

	
	for (i=1, c=1; i<n; i++, c++) {
		scanf("%d", &v);

		if (n%2 == 0) {
			if (c%2 == 1) dq.push_back(v);
			else dq.push_front(v);	
		}
		else {
			if (c%2 == 0) dq.push_back(v);
			else dq.push_front(v);
		}
		

	}

	printf("%d", dq.back());
	dq.pop_back();

	while(!dq.empty()) {
		printf(" %d", dq.back());
		dq.pop_back();
	}
	printf("\n");
}