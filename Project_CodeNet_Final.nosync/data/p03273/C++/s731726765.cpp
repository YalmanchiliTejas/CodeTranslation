/*

*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#define Pair pair<int, int>
#define MP(x, y) make_pair(x, y)
#define fi first
#define se second
//#define int long long 
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 22)], *p1 = buf, *p2 = buf;
using namespace std;
const int MAXN = 1e6 + 10, INF = 1e9 + 10;
const double eps = 1e-9;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int r[MAXN], l[MAXN];
char s[1001][1001];
int main() {
	int N = read(), M = read();
	for(int i = 1; i <= N; i++)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= N; i++) {
		r[i] = 1;
		for(int j = 1; j <= M; j++)
			if(s[i][j] == '#') {r[i] = 0; break;}
	}
	for(int i = 1; i <= M; i++) {
		l[i] = 1;
		for(int j = 1; j <= N; j++) {
			if(s[j][i] == '#') {l[i] = 0; break;}
		}
	}
	for(int i = 1; i <= N; i++) {
		if(r[i]) continue;
		for(int j = 1; j <= M; j++)
			if(l[j] == 0)
				putchar(s[i][j]);	
		puts("");	
	} 

    return 0;
}
/*

*/