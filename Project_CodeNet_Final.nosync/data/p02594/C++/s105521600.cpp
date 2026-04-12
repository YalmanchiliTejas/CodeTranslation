#include <bits/stdc++.h>
 
using namespace std;

#ifdef ARTEM
	#define deb(x) x
#else
	#define deb(x)
	const int LIMIT = 2 * int(1e5) + 123;
#endif

void solve();

int main() {
	solve();
}

/* ================ actual code starts here ================ */

void solve() {
	int t;
	scanf("%d", &t);
	if(t >= 30)
		printf("Yes\n");
	else
		printf("No\n");
}