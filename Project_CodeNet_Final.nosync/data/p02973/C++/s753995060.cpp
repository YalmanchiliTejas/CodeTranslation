#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int tree[N << 2];
inline void pushup(int rt){
	tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}
inline void update(int p, int l, int r, int rt, int x){
	if(l == r){
		tree[rt] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= p)update(p, l, mid, rt << 1, x);
	else update(p, mid + 1, r, rt << 1 | 1, x);
	pushup(rt);
}
inline int query(int x, int y, int l, int r, int rt){
	if(x <= l && r <= y)return tree[rt];
	int mid = (l + r) >> 1, ans = 0;
	if(mid >= x)ans = max(ans, query(x, y, l, mid, rt << 1));
	if(mid < y)ans = max(ans, query(x, y, mid + 1, r, rt << 1 | 1));
	return ans;
}
int x[N], a[N], hsh[N];
inline bool cmp(int x, int y){
	return a[x] < a[y];
}
int tot = 0;
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)scanf("%d", &a[i]), x[i] = i;
	sort(x + 1, x + n + 1, cmp); a[0] = -1;
	for(int i = 1; i <= n; ++ i){
		if(a[x[i]] != a[x[i - 1]])
			++ tot;
		hsh[x[i]] = tot;
	}
	int mx = 1;
	update(hsh[1], 1, tot, 1, 1);
	for(int i = 2; i <= n; ++ i){
		int t = query(hsh[i], tot, 1, tot, 1);
		mx = max(mx, t + 1);
		update(hsh[i], 1, tot, 1, t + 1);
	}
	printf("%d", mx);
	return 0;
}