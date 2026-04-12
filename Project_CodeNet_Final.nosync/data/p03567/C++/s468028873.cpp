#include <bits/stdc++.h>
using namespace std;
char s[10];
int main () {
	cin >> s;
	bool f = false;
	for (int i = 0; i < 4; i++)
		if (s[i] == 'A' && s[i + 1] == 'C')
			f = true;
	if (f) puts("Yes");
	else puts("No");
	return 0;
}