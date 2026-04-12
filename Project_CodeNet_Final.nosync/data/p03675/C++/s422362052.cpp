#include <bits/stdc++.h>
using namespace std;

int main (int argc, char const* argv[])
{
	deque <int> Q;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		if((i & 1) != (n & 1)) Q.push_back(c);
		else Q.push_front(c);
	}
	while(!Q.empty()) {
		printf("%d ", Q.front());
		Q.pop_front();
	}
	printf("\n");
	return 0;
}