#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

const int N = 130, M = N*N;
int n, m;
int d[15][15], p[N][N];
int x[M], y[M], v[M], cnt;

int dis(int A, int B) {
	int ret = 101, i, j;
	rep(i, 0, 100)
		rep(j, 0, 100)
			if(p[i][j] >= 0) ret = min(ret, i*A + j*B + p[i][j]);
	return ret;
}

int main() {
	int i, j, k, A, B; bool f = 1;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &d[i][j]);
	rep(A, 0, 100)
		rep(B, 0, 100) {
			p[A][B] = -100;
			rep(i, 1, n)
				rep(j, 1, m) {
					p[A][B] = max(p[A][B], d[i][j] - i*A - j*B);
				}
			if(p[A][B] >= 0) {
				++cnt;
				x[cnt] = A+1; y[cnt] = B+102; v[cnt] = p[A][B];				
			}
		}
		
	rep(i, 1, n) rep(j, 1, m) 
	if(dis(i, j) != d[i][j]) {puts("Impossible"); return 0;}
		
	
	puts("Possible");
	printf("%d %d\n", 202, cnt+200);
	rep(i, 1, cnt) printf("%d %d %d\n", x[i], y[i], v[i]);
	rep(i, 2, 101) printf("%d %d X\n", i-1, i);
	rep(i, 103, 202) printf("%d %d Y\n", i, i-1);
	puts("1 102");
	return 0;
}