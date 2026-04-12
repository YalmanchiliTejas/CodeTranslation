#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	if ((a * 100 + b * 10 + c) % 4) {
		puts("NO");
	} else {
		puts("YES");
	}
}