#include <bits/stdc++.h>
using namespace std;

char s[100];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i < n; ++i) if (s[i] == 'A' && s[i + 1] == 'C') return printf("Yes\n"), 0;
	return printf("No\n"), 0;
}