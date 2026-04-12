#include<cstdio>
#include<algorithm>
#define N_ 201000
using namespace std;
int R[N_];
struct point {
	int x, num;
	bool operator<(const point &p)const {
		return x<p.x;
	}
}w[N_];
int main() {
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i].x);
		w[i].num = i;
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n / 2; i++)R[w[i].num] = w[n / 2 + 1].x;
	for (i = n / 2 + 1; i <= n; i++)R[w[i].num] = w[n / 2].x;
	for (i = 1; i <= n; i++)printf("%d\n", R[i]);
}