#include<bits/stdc++.h>
#define LL long long  
using namespace std;
const int MAXN = 101;
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int N, M, cnt;
char s[MAXN][MAXN];
void dfs(int i, int j, int num) {
	if(i == N && j == M) {
		if(num == cnt) puts("Possible");
		else puts("Impossible");
		exit(0);
	}
	if(s[i + 1][j] == '#') dfs(i + 1, j, num + 1);
	if(s[i][j + 1] == '#') dfs(i, j + 1, num + 1);
}
int main() {
	N = read(), M = read();
	for(int i = 1; i <= N; i++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= M; j++) if(s[i][j] == '#') cnt++;
	}
	dfs(1, 1, 1);
	puts("Impossible");
	return 0;
}
/*
1
2 21
*/
