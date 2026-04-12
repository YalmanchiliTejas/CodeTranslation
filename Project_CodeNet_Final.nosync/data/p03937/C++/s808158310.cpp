#include<bits/stdc++.h>
using namespace std;

int n, m, l[10], r[10];
char s[10][10];

inline void end() {
	printf("Impossible\n");
	exit(0);
}

int main() {
	cin >> n >> m;
	r[0] = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i]+1);
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '#' && s[i][j-1] != '#') {
				if(l[i]) end();
				l[i] = j;
			}
			if(s[i][j] != '#' && s[i][j-1] == '#') {
				if(r[i]) end();
				r[i] = j-1;
			}
		}
		if(!r[i]) r[i] = m;
		//printf("%d %d\n", l[i], r[i]);
		if(l[i] != r[i-1]) end();
	}
	printf("Possible\n");
	return 0;
}
