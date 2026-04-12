#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int n, m;
int l[maxn], r[maxn], a[maxn];
long long int seg[maxn<<2], lazy[maxn<<2];
vector<int> cnt[maxn];

void put(long long int x, int id){
	lazy[id] += x;
	seg[id] += x;
}

void shift(int id, int l, int r){
	if (r - l > 1 && lazy[id] != 0){
		put(lazy[id], id<<1);
		put(lazy[id], id<<1|1);
	}
	lazy[id] = 0;
}

void sett(int pos, long long int x, int id = 1, int l = 0, int r = n+1){
	if (r - l < 2){
		seg[id] = x;
		return ;
	}

	shift(id, l, r);

	int mid = (l+r)>>1;
	if (pos < mid)
		sett(pos, x, id<<1, l, mid);
	else
		sett(pos, x, id<<1|1, mid, r);

	seg[id] = max(seg[id<<1], seg[id<<1|1]);
}

void update(int L, int R, long long int x, int id = 1, int l = 0, int r = n+1){
	if (L <= l and r <= R){
		put(x, id);
		return ;
	}

	if (R <= l or r <= L)
		return ;

	shift(id, l, r);

	int mid = (l+r)>>1;
	update(L, R, x, id<<1, l, mid);
	update(L, R, x, id<<1|1, mid, r);
	seg[id] = max(seg[id<<1], seg[id<<1|1]);
}

long long int query(int L, int R, int id = 1, int l = 0, int r = n+1){
	if (L <= l and r <= R)
		return seg[id];

	if (R <= l or r <= L)
		return 0;

	shift(id, l, r);

	int mid = (l+r)>>1;
	return max(query(L, R, id<<1, l, mid), query(L, R, id<<1|1, mid, r));
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &l[i], &r[i], &a[i]);
		cnt[r[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++){
		sett(i, query(0, i));

		for (int id: cnt[i]){
			update(l[id], r[id]+1, a[id]);
		}
	}

	cout << seg[1] << endl;
	return 0;
}
