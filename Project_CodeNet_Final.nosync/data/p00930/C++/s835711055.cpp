#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 301000
int n;
char str[MAXN];
int diff[MAXN];
struct Node {
	int start, end;
	int minv, flag, add;
	void operator += (const int& val) {
		minv += val;
		flag += val;
		add += val;
	}
} tree[MAXN<<2];
void pushdown (int o) {
	if (tree[o].add) {
		tree[o<<1] += tree[o].add;
		tree[o<<1|1] += tree[o].add;
		tree[o].add = 0;
	}
}
void pushup (int o) {
	tree[o].minv = min(tree[o<<1].minv, tree[o<<1|1].minv);
	tree[o].flag = min(tree[o<<1].flag, tree[o<<1|1].flag);
}
void build (int o, int start, int end) {
	tree[o].start = start;
	tree[o].end = end;
	tree[o].add = 0;
	if (start == end) {
		tree[o].flag = diff[start] - start;
		tree[o].minv = diff[start];
		return;
	}
	int mid = (start + end) >> 1;
	build(o<<1, start, mid);
	build(o<<1|1, mid + 1, end);
	pushup(o);
}
void update (int o, int pos, int val) {
	//printf ("%d %d %d\n", tree[o<<1].start, tree[o].end, pos);
	if (pos <= tree[o].start) {
		tree[o] += val;
		return;
	}
	pushdown(o);
	if (pos <= tree[o<<1].end)
		update(o<<1, pos, val);
	update(o<<1|1, pos, val);
	pushup (o);
}
int query1 (int o) {
	//printf ("%d: %d %d %d\n", 1, tree[o].start, tree[o].end, tree[o<<1].flag);
	if (tree[o].start == tree[o].end)
		return tree[o].start;
	pushdown(o);
	int r;
	if (tree[o<<1].flag < 0)
		r = query1(o<<1);
	else
		r = query1(o<<1|1);
	pushup(o);
	return r;
}
int query2(int o) {
	//printf ("%d: %d %d %d\n", 2, tree[o].start, tree[o].end, tree[o<<1].minv);
	if (tree[o].start == tree[o].end)
		return tree[o].minv < 2 ? INF : tree[o].start;
	pushdown(o);
	int r;
	if (tree[o<<1|1].minv < 2)
		r = query2(o<<1|1);
	else
		r = min(query2(o<<1), tree[o<<1|1].start);
	pushup(o);
	return r;
}
int main () {
#ifdef TXT
	freopen ("in.txt", "r", stdin);
#endif
	int q, pos;
	while (~scanf ("%d%d", &n, &q)) {
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i ++)
			diff[i] = diff[i - 1] + (str[i] == '(' ? 1 : -1);
		//for (int i = 1; i <= n; i ++)
		//	printf ("%d ", diff[i]);
		//printf ("\n");
		build(1, 1, n);
		query1(1);
		while (q --) {
			scanf ("%d", &pos);
			update(1, pos, str[pos] == '(' ? -2 : 2);
			str[pos] = str[pos] == ')' ? '(' : ')';
			pos = str[pos] == ')' ? query1(1) : query2(1);
			//printf ("%d %s\n", pos, str + 1);
			update(1, pos, str[pos] == '(' ? -2 : 2);
			str[pos] = str[pos] == ')' ? '(' : ')';
			printf ("%d\n", pos);
		}
	}
	return 0;
}