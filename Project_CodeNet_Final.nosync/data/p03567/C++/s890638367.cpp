#include <bits/stdc++.h>

using namespace std;

char s[11];

int main() {
	ignore = scanf("%s", s);
	
	bool ans = false;
	for (int i = 0; s[i + 1] != 0; i++) ans = ans || (s[i] == 'A' && s[i + 1] == 'C');
	
	printf(ans ? "Yes\n" : "No\n");
	
	return 0;
}
