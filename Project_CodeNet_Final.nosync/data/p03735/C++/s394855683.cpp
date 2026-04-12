#include <stdio.h>
#pragma warning(disable:4996)
//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x7fffffff
#define NM 100005
#define MOD 1000000007
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define sd(n) fscanf(in,"%lld",&n)
typedef long long int ll;

int n, check[NM * 2], N;
struct LIST {
	ll x;
	int idx;
	bool operator()(const LIST& A, const LIST& B) {
		return A.x < B.x;
	}
}p[NM*4];
void input() {
	si(n); N = n * 2;
	FOR(i, 1, n) {
		int a, b; si(a), si(b);
		if (a > b) swap(a, b);
		p[i * 2 - 1].x = a; p[i * 2 - 1].idx = i;
		p[i * 2].x = b; p[i * 2].idx = i;
	}
	sort(p + 1, p + 1 + N, LIST());
}
ll case1() {
	FOR(i, 1, n) check[i] = 0;
	ll res = 1e18;
	int L = 1, R = N + 1;
	check[p[1].idx] = 1;
	while (check[p[R - 1].idx] == 0) check[p[--R].idx] = 1;
	if (R <= N) res = min(res, (p[N].x - p[1].x)*(p[R - 1].x - p[L + 1].x));
	for (L=2;L<=N;L++){
		while (check[p[L].idx] == 1 && R <= N) check[p[R++].idx] = 0;
		if (R == N + 1) break;
		check[p[L].idx] = 1;
		res = min(res, (p[N].x - p[1].x)*(p[R - 1].x - p[L + 1].x));
	}
	return res;
}
ll case2() {
	FOR(i, 1, n) check[i] = 0;
	int L = 1, R = N;
	check[p[1].idx] = 1;
	check[p[N].idx] = 2;
	while ((check[p[L + 1].idx] & 1) == 0)
		check[p[++L].idx] ^= 1;
	while ((check[p[R - 1].idx] & 2) == 0)
		check[p[--R].idx] ^= 2;
	return (p[N].x - p[L + 1].x)*(p[R - 1].x - p[1].x);
}
int main() {
	input();
//	fprintf(out, "%lld %lld ", case1(), case2());
	fprintf(out, "%lld", min(case1(), case2()));
	return 0;
}