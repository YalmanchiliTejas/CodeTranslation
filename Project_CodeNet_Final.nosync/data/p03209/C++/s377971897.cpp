#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = inx(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

/*

https://atcoder.jp/contests/abc121/tasks/abc121_d

	ll A, B, ans, cnt1, cnt2, cnt;
	cin >> A >> B;
	ans = 0;
	vl v(50);
	v[0] = 1;
	rep(i, 50) v[i + 1] = v[i] * 2;
	rep2(i, 1, 50){
		cnt1 = min(v[i] / 2, v[i] - (A % v[i]));
		cnt2 = max((ll)0, -1 + (B % v[i]));
		cnt = cnt1 + cnt2;
		print2(cnt1, cnt2);
		if(cnt % 2) ans += v[i];
	}
	print(ans);
	
*/

vl v(100);
vl p(100);

ll rev(ll level, ll x){
	
	if(x <= 0) return 0;
	if(level == 0) return 1;
	if(x == 1) return 0;
	if(x <= 1 + v[level - 1]) return rev(level - 1, x - 1);
	if(x == v[level - 1] + 2) return 1 + p[level - 1]; 
	if(x <= 2 * v[level - 1] + 2) return 1 + rev(level - 1, x - 2 - v[level - 1]) + p[level - 1]; 
	return 1 + 2 * p[level - 1];
	
}

void solve(){
	
	ll N, X, ans;
	cin >> N >> X;
	v[0] = 1;
	rep2(i, 1, 60) v[i] = 3 + 2 * v[i - 1];
	p[0] = 1;
	rep2(i, 1, 60) p[i] = 1 + 2 * p[i - 1];
	ans = rev(N, X);
	print(ans);	
	
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}