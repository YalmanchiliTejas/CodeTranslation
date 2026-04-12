#include <stdio.h>
#include <string.h>
#define lson rt<<1
#define rson rt<<1|1
#define mid ((l+r)>>1)
#define clr(a, b) memset(a, b, sizeof(a))
inline int min(int a, int b){return a<b?a:b;}
const int MAX_N = 300010;
struct SegTree{
	int f, a, lazy;
}node[MAX_N << 2];
char s[MAX_N];
int N, Q, k;

void pushup(int rt){
	node[rt].a = min(node[lson].a, node[rson].a);
	node[rt].f = min(node[lson].f, node[rson].f);
}

void pushdown(int rt){
	if (node[rt].lazy){
		node[lson].lazy += node[rt].lazy;
		node[rson].lazy += node[rt].lazy;
		node[lson].a += node[rt].lazy;
		node[rson].a += node[rt].lazy;
		node[lson].f += node[rt].lazy;
		node[rson].f += node[rt].lazy;
		node[rt].lazy = 0;
	}
}

void build(int l, int r, int rt, int a, int p){
	node[rt].lazy = 0;
	if(l == r){
		node[rt].f = a - l;
		node[rt].a = a;
		return ;
	}
	if (p <= mid) build(l, mid, lson, a, p);
	else build(mid+1, r, rson, a, p);
	pushup(rt);
}

void init(){
	clr(node, 0);
	int sum = 0;
	for (int i = 1;i <= N;++i){
		sum += (s[i] == '(' ? 1 : -1);
		build(1, N, 1, sum, i);
	}
}

void update(int L, int R, int val, int l, int r, int rt){
	if (L <= l && r <= R){
		node[rt].lazy += val;
		node[rt].f += val;
		node[rt].a += val;
		return ;
	}
	pushdown(rt);
	if (L <= mid)	update(L, R, val, l, mid, lson);
	if (R > mid)	update(L, R, val, mid+1, r, rson);
	pushup(rt);
}

int query1(int l, int r, int rt){
	if (l == r)	return l;
	pushdown(rt);
	if (node[lson].f < 0)	return query1(l ,mid, lson);
	return query1(mid+1, r, rson);
}

int query2(int l, int r, int rt){
	if (l == r)	return l+1;
	pushdown(rt);
	if (node[rson].a < 2)	return query2(mid+1, r, rson);
	return query2(l, mid, lson);	
}

int main(){
	while (~scanf("%d %d", &N, &Q)){
		scanf("%s", s+1);
		init();
		while (Q--){
			scanf("%d", &k);
			bool flag = (s[k] == '(');
			s[k] = flag ? ')' : '(';
			update(k, N, flag ? -2 : 2, 1, N, 1);
			k = (flag ? query1(1, N, 1) : query2(1, N, 1));
			flag = (s[k] == '(');
			s[k] = flag ? ')' : '(';
			update(k, N, flag ? -2 : 2, 1, N, 1);
			printf("%d\n", k);
		}
	}
	return 0;
}