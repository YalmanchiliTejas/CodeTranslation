#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
LL tree[maxn << 4], lazy[maxn << 4];
struct node{int l, a;node(int l = 0, int a = 0): l(l), a(a){}};
vector<node> s[maxn];
void pushdown(int o){
	lazy[o * 2] += lazy[o];
	tree[o * 2] += lazy[o];
	lazy[o * 2 + 1] += lazy[o];
	tree[o * 2 + 1] += lazy[o];
	lazy[o] = 0;
}
void update(int o, int l, int r, int L, int R, LL v){
	if(l >= L and r <= R){
		tree[o] += v;
		lazy[o] += v;
	}
	else{
		int m = (l + r) >> 1;
		pushdown(o);
		if(L <= m) update(o * 2, l, m, L, R, v);
		if(R > m) update(o * 2 + 1, m + 1, r, L, R, v);
		tree[o] = max(tree[o * 2], tree[o * 2 + 1]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	while(M --){
		int l, r, a;
		cin >> l >> r >> a;
		s[r].push_back(node(l, a));
	}
	for(int i = 1; i <= N; i += 1){
		update(1, 1, N, i, i, tree[1]);
		for(node p: s[i]) update(1, 1, N, p.l, i, p.a);
	}
	cout << max(0LL, tree[1]);
}