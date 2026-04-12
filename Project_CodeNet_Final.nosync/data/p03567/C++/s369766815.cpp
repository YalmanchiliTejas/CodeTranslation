#include <stdio.h>
#include <algorithm>

int main() {
	char s[6] = { 0 };
	scanf("%s", s);

	bool res = false;
	for (int i = 0; i < 4; i++)
		res |= s[i] == 'A' && s[i + 1] == 'C';

	printf("%s\n", res ? "Yes" : "No");
}