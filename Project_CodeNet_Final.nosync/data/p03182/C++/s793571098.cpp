#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 2e5 + 300, N2 = 2e3, inf = 1e9 + 200;

int t[4*N], c[4*N];
int d[N];

vector <int> L[N], R[N];
/*
void push(int v, int l, int r){
	t[v] += c[v];
	if (l != r){
		c[v+v] += c[v];
		c[v+v+1] += c[v];
	}
	c[v] = 0;
}

void update (int v, int ll, int rr, int l, int r, int res){
	push(v, ll, rr);
	if (ll > r || rr < l) return;
	if (ll >= l && rr <= r){
		c[v] += res;
		push(v, ll, rr);
	}
	else{
		int mid = (ll + rr) / 2;
		update(v+v, ll, mid, l, r, res);
		update(v+v+1, mid + 1, rr, l, r, res);
		t[v] = max(t[v+v], t[v+v+1]);
	}
}

int maxi(int v, int ll, int rr, int l, int r){
	push(v, ll, rr);
	if (ll > r || rr < l){
		return -1;
	}
	if (ll >= l && rr <= r){
		return t[v];
	}
	int mid = (ll + rr) / 2;
	return max(maxi(v+v, ll, mid, l, r), maxi(v+v+1, mid + 1, rr, l, r));
}*/

void propagate(int pos,int left,int right){

	if(c[pos] == 0) return;

	if(left != right){
		c[2*pos] += c[pos];
		c[2*pos+1] += c[pos];
	}

	t[pos] += c[pos];
	c[pos] = 0;

}

void update(int pos,int left, int right,int i,int j, int delta){

	propagate(pos,left,right);
	if(left > right || left > j || right < i) return;

	if(left >= i && right <= j){
		c[pos] += delta;
		propagate(pos,left,right);
		return;
	}

	int mid = (left+right)/2;
	update(2*pos,left,mid,i,j,delta);
	update(2*pos+1,mid+1,right,i,j,delta);

	t[pos] = max(t[2*pos],t[2*pos+1]);

}

int maxi(int pos,int left,int right,int i,int j){

	propagate(pos,left,right);

	if(left >= i && right <= j) return t[pos];

	int mid = (left+right)/2;
	if(j <= mid) return maxi(2*pos,left,mid,i,j);
	else if(i >= mid + 1) return maxi(2*pos+1,mid+1,right,i,j);
	else return max(maxi(2*pos,left,mid,i,j), maxi(2*pos+1,mid+1,right,i,j));

}

int l[N], r[N], x[N];

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> l[i] >> r[i] >> x[i];
		L[l[i]].pb(i);
		R[r[i]].pb(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for(int j : L[i]){
			update(1, 0, n, 0, l[j] - 1, x[j]);
		}
		d[i] = maxi(1, 0, n, 0, i - 1); 
		ans = max(ans, d[i]);
		update(1, 0, n, i, i, d[i]);
		for(int j : R[i]){
			update(1, 0, n, 0, l[j] - 1, -x[j]);
		}
	}
	cout << ans;
	
	return 0;
}

/*
for(int i = 1;i<=N;i++){
		for(int j : adiciona[i]){
			update(1,0,N,0,ini[j] - 1,valor[j]);
		}
		dp[i] = query(1,0,N,0,i-1);
		update(1,0,N,i,i,dp[i]);
		for(int j : retira[i]){
			update(1,0,N,0,ini[j] - 1,-valor[j]);
		}
	}*/







