#include<cstdio>
#include<algorithm>
#define N_ 101000
using namespace std;
struct point {
	int x, num;
	bool operator<(const point &p)const {
		return x<p.x;
	}
}X[N_], Y[N_];
struct Edge {
	int a, b, c;
	bool operator <(const Edge &p)const {
		return c < p.c;
	}
}E[2 * N_];
int UF[N_];
int n;
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &X[i].x, &Y[i].x);
		X[i].num = Y[i].num = i;
		UF[i] = i;
	}
	sort(X + 1, X + n + 1);
	sort(Y + 1, Y + n + 1);
	int cnt = 0;
	for (i = 1; i < n; i++) {
		E[cnt++] = { X[i].num,X[i + 1].num,X[i + 1].x - X[i].x };
		E[cnt++] = { Y[i].num,Y[i + 1].num,Y[i + 1].x - Y[i].x };
	}
	sort(E, E + cnt);
	int res = 0;
	for (i = 0; i < cnt; i++) {
		if (Find(E[i].a) != Find(E[i].b)) {
			res += E[i].c;
			UF[Find(E[i].a)] = Find(E[i].b);
		}
	}
	printf("%d\n", res);
}