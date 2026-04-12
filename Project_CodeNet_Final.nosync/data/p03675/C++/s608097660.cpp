#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	deque<int> dq;
	for (int i=0; i<n; i++) {
		int a; scanf("%d", &a);
		if (i%2==0) dq.push_back(a);
		else dq.push_front(a);
	}
	for (int i=0; i<n; i++) printf("%d%c", dq[n%2==0 ? i : n-i-1], i==n-1 ? '\n' : ' ');
	
}
