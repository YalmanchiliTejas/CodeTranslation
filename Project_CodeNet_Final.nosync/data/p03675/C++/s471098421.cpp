/*input
5
1 2 3 4 5 
*/

#include <bits/stdc++.h> 

using namespace std;

int n;
deque<int> dq;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if ((i & 1) == (n & 1)) dq.push_front(x);
		else dq.push_back(x);
	}
	for (int x : dq) printf("%d ", x);
}