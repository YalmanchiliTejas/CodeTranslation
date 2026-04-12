#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back

const int N = 1<<18;

using namespace std;

int n, m;
ll dp[N];
pll seg[2*N];
vector<pll > ra[N];

void push(int k){
	seg[k].F += seg[k].S;
	if(k<N){
		seg[2*k].S += seg[k].S;
		seg[2*k+1].S += seg[k].S;
	}
	seg[k].S = 0;
}

ll add(int a, int b, int k, int x, int y, ll o){

	if(seg[k].S) push(k);
	if(a>y || b<x) return seg[k].F;
	if(a==x && b==y){
		seg[k].S += o;
		return seg[k].F+o;
	}

	int d = (y-x+1)/2;

	ll lst = add(a, min(b, y-d), 2*k, x, y-d, o);
	ll rst = add(max(a, x+d), b, 2*k+1, x+d, y, o);

	seg[k].F = max(lst, rst);

	return seg[k].F;
}

ll mas(int a, int b, int k, int x, int y){
	
	if(a>y || b<x) return -1e18;
	if(seg[k].S) push(k);
	if(a==x && b==y) return seg[k].F;

	int d = (y-x+1)/2;

	ll lst = mas(a, min(b, y-d), 2*k, x, y-d);
	ll rst = mas(max(a, x+d), b, 2*k+1, x+d, y);

	return max(lst, rst);
}

int main(){

	cin >> n >> m;

	for(int i=0; i<m; i++){
		int l, r, a;
		cin >> l >> r >> a;
		ra[l].pb({r, a});
	}

	for(int i=n; i>0; i--){
		dp[i] = mas(i, n+1, 1, 0, N-1);
		add(i, i, 1, 0, N-1, dp[i]);
		for(pii j : ra[i]) add(i, j.F, 1, 0, N-1, j.S);
	}

	cout << mas(1, n+1, 1, 0, N-1) << endl;

	return 0;
}
