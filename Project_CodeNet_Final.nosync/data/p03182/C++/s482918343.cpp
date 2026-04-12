/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Os")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
*/
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld; 

#define X first
#define Y second
#define MP make_pair

using namespace std;
    
const int N = 3e5 + 123;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

ll t[N * 4], tt[N * 4], dp[2][N], dz[N];
vector< pair<int, ll> > g[N];
vector< ll > gg[N];
int n;

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = -INF;
		return;
	}	
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void push(int v){
	if(tt[v] == 0)
		return;
	t[v * 2] += tt[v], t[v * 2 + 1] += tt[v];
	tt[v * 2] += tt[v], tt[v * 2 + 1] += tt[v];
	tt[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, ll val){
	if(tl > r || l > tr)
		return;
	if(tl >= l && tr <= r){
		t[v] += val;
		tt[v] += val;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	upd(v * 2, tl, tm, l, r, val);
	upd(v * 2 + 1, tm + 1, tr, l, r, val);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

ll get(int v, int tl, int tr, int l, int r){
	if(tl > r || tr < l)
		return -INF;
	if(tl >= l && tr <= r){
		return t[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int q;
	cin >> q;
	for(int i = 1;i <= q;i++){
		int l, r, v;
		cin >> l >> r >> v;
		g[r].push_back(MP(l, v));
	}

	for(int i = 1;i <= n;i++){
		upd(1, 1, n, i, i, max(0LL, get(1, 1, n, 1, i)));
		for(int j = (int)g[i].size() - 1;j >= 0;j--){
			upd(1, 1, n, g[i][j].X, i, g[i][j].Y);
		}		
	}
	cout << max(0LL, t[1]);
	return 0;
}