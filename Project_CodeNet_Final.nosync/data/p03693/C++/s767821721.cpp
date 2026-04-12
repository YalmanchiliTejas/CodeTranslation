#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int r, g, b;

	scanf("%d %d %d", &r, &g, &b);

	int num = b + 10*g + 100*r;

	if (num % 4 == 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}