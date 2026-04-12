#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[100010], B[100010], F[100010], tmp1[100010], tmp2[100010];

int dis(int op, int x, int y)
{
	if(op == 1) x = tmp1[x], y = tmp1[y]; else x = tmp2[x], y = tmp2[y];
	return min(abs(A[x] - A[y]), abs(B[x] - B[y]));
}

bool cmp1(int x, int y) {return A[x] < A[y];}
bool cmp2(int x, int y) {return B[x] < B[y];}

struct node {int op, x, y, ds; node(){} node(int a, int b, int c, int d) {op = a, x = b, y = c, ds = d;} bool operator < (const node& X) const {return ds > X.ds;}}; //!!! //!!!!!

int getf(int x) {return F[x] == x ? x : F[x] = getf(F[x]);}

priority_queue <node> hsh;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]), F[i] = i, tmp1[i] = tmp2[i] = i;
	sort(tmp1 + 1, tmp1 + n + 1, cmp1), sort(tmp2 + 1, tmp2 + n + 1, cmp2);
	for(int i = 1; i < n; i++) hsh.push(node(1, i, i + 1, dis(1, i, i + 1))), hsh.push(node(2, i, i + 1, dis(2, i, i + 1)));
	long long ans = 0;
	for(int T = 1; T < n;) {
		node tmp = hsh.top();
		hsh.pop();
		int a = tmp.op == 1 ? tmp1[tmp.x] : tmp2[tmp.x], b = tmp.op == 1 ? tmp1[tmp.y] : tmp2[tmp.y];
		if(getf(a) != getf(b)) ans += dis(tmp.op, tmp.x, tmp.y), T++, F[getf(a)] = getf(b);
		if(tmp.y != n) hsh.push(node(tmp.op, tmp.x, tmp.y + 1, dis(tmp.op, tmp.x, tmp.y + 1)));
	}
	printf("%lld\n", ans);
	return 0;
}