#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> ii;

int N = 200002;
vector<ii> intervals[200005];

int tree[400015];
int lazy[400025];

void pull(int i){
	if(i >= N) tree[i] = lazy[i];
	else tree[i] = max(tree[i<<1], tree[i<<1|1]) + lazy[i];
}

void push(int i){
	tree[i<<1] += lazy[i];
	lazy[i<<1] += lazy[i];
	tree[i<<1|1] += lazy[i];
	lazy[i<<1|1] += lazy[i];
	lazy[i] = 0;
}

void prop(int i){
	if(i != 1) prop(i >> 1);
	if(i < N) push(i);
}

void update(int L, int R, int v){
	for(int l = L+N, r = R+N;l < r;l >>= 1, r >>= 1){
		if(l&1){
			lazy[l] += v;
			pull(l);
			l++;
		}
		if(r&1){
			r--;
			lazy[r] += v;
			pull(r);
		}
	}
	
	for(L += N;L > 0;L >>= 1) pull(L);
	for(R += N-1;R > 0;R >>= 1) pull(R);
}

int query(int l, int r){
	prop(l+N); prop(r+N-1);
	
	int ans = -10234567891232;
	for(l += N,r += N;l < r;l >>= 1, r >>= 1){
		if(l&1) ans = max(ans, tree[l++]);
		if(r&1) ans = max(ans, tree[--r]);
	}
	return ans;
}

signed main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 0;i < m;i++){
		int l, r, v; cin >> l >> r >> v;
		intervals[r+1].push_back(ii(l,-v));
		intervals[l].push_back(ii(l,v));
	}
	
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(ii x : intervals[i]) update(0, x.first, x.second);
		
		int dp = 0;
		dp = query(0,i);
		ans = max(ans, dp);
		update(i,i+1,dp);
	}
	
	cout << ans;
}
