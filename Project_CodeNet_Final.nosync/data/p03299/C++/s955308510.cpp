#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t3;

int N, h[110];
ll d[110][210];
const ll MOD = 1e9 + 7;
ll pw(int x, int y) {
	ll res = 1;
	while(y) {
		if(y & 1) res = res * x % MOD;
		x = (ll)x * x % MOD;
		y >>= 1;
	}
	return res;
}

ll get_pw2(int l, int r) {
	ll val = pw(2, r + 1);
	val = (val + MOD - pw(2, l)) % MOD;
	return val;
}

vector <int> hv;
pii get_seg(int v) {
	if(v == 1) return pii(1, hv[0] - 1);
	if(v % 2 == 0) return pii(hv[v/2-1], hv[v/2-1]);
	else return pii(hv[v/2-1] + 1, hv[v/2] - 1);
}

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", h+i);
	for(int i=1;i<=N;i++) hv.pb(h[i]);
	sort(all(hv)); hv.resize(unique(all(hv)) - hv.begin());
	for(int i=1;i<=N;i++) h[i] = (int)(lower_bound(all(hv), h[i]) - hv.begin());
	for(int i=1;i<=2*h[1]+2;i++) {
		pii s = get_seg(i);
		if(s.Fi <= s.Se) {
			int lv = hv[h[1]] - s.Se;
			int rv = hv[h[1]] - s.Fi;
			d[1][i] = get_pw2(lv, rv);
		}
		if(i == 2*h[1]+2) d[1][i] = (d[1][i] + 1) % MOD;
	}
	for(int i=1;i<N;i++) {
		if(h[i] >= h[i+1]) {
			for(int j=1;j<=2*h[i+1]+1;j++) {
				d[i+1][j] = (d[i+1][j] + d[i][j]) % MOD;
			}
			ll sum = 0;
			for(int j=2*h[i+1]+2;j<=2*h[i]+2;j++) {
				sum = (sum + d[i][j]) % MOD;
			}
			d[i+1][2*h[i+1]+2] = (d[i+1][2*h[i+1]+2] + sum * 2) % MOD;
		}
		else {
			for(int j=1;j<=2*h[i]+1;j++) {
				d[i+1][j] = (d[i+1][j] + (ll)pw(2, hv[h[i+1]] - hv[h[i]]) * d[i][j]) % MOD;
			}
			for(int j=2*h[i]+2;j<=2*h[i+1]+2;j++) {
				pii s = get_seg(j);
				int lv = hv[h[i+1]] - s.Se;
				int rv = hv[h[i+1]] - s.Fi;
				ll val = get_pw2(lv, rv);
				if(j == 2*h[i+1]+2) val = 2;
				d[i+1][j] = (d[i+1][j] + val * d[i][2*h[i]+2]) % MOD;
			}
		}
	}
	
	ll sum = 0;
	rep(i, 210) sum = (sum + d[N][i]) % MOD;
	printf("%lld\n", sum);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}