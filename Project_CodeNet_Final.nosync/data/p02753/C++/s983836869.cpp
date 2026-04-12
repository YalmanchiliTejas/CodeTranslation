#include <bits/stdc++.h>

using namespace std;

char s[5];

int main() {
	scanf("%s", s);
	int test = (int)s[0] + s[1] + (int)s[2];
	if (test == 195 || test == 198) printf("No\n");
	else printf("Yes\n");
	return 0;
}
