#include <bits/stdc++.h>
using namespace std;
char s[20][20];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for (int i = 0; i < n; ++ i) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++ j) if (s[i][j] == '#') cnt ++;
	}
	puts(cnt == n + m - 1 ? "Possible" : "Impossible");
}

