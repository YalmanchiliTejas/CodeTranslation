#include <bits/stdc++.h>

using namespace std;

int main() {
	int a = 0, b = 0;
	char c[4];

	scanf("%s", c);

	for (int i=0; i<3; ++i) {
		if (c[i] == 'A')
			++a;
		else
			++b;
	}

	if (a && b)
		puts("Yes");
	else
		puts("No");
	
	return 0;
}