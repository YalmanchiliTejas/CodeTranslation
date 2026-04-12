#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int N = 250000;
const int B = 500;
const int BKT = (N + B - 1) / B;

int n, s[N], mx[BKT], mn[BKT], add[BKT];
inline void update(int i){
	if(i * B >= n / 2) return;
	int m = inf, M = -inf;
	for(int j = i * B; j < n / 2 && j < (i + 1) * B; j++){
		m = min(m, s[j]);
		M = max(M, s[j]);
	}
	mn[i] = m; mx[i] = M;
}
void query(int l, int r, int x){
	while(l < r && l % B) s[l++] += x; update(max(0, l / B - 1));
	while(l < r && r % B) s[--r] += x; update(r / B);
	
	l /= B; r /= B;
	while(l < r) add[l++] += x;
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	rep(i, n){
		int a; cin >> a;
		if(i < n / 2) s[i] += a;
		else s[n - i - 1] -= a;
	}
	for(int i = 0; i < BKT; i++) update(i);
	
	int q; cin >> q;
	while(q--){
		int l, r, x; cin >> l >> r >> x; l--;
		if     (r <= n / 2) query(l, r, x);
		else if(l >= n / 2) query(n - r, n - l, -x);
		else{
			query(l, n / 2, x);
			query(n - r, n / 2, -x);
		}
		/*
		rep(i, n / 2) cerr<<s[i]+add[i/B]<<" ";cerr<<endl;
		rep(i, n / 2) cerr<<mx[i/B]<<" ";cerr<<endl;
		rep(i, n / 2) cerr<<mn[i/B]<<" ";cerr<<endl;
		*/
		int res = 1;
		rep(i, BKT) if(!(mx[i] == mn[i] && mx[i] + add[i] == 0)) res = 0;
		/*
		rep(i, BKT) if(!(mx[i] == mn[i] && mx[i] + add[i] == 0)){
			dbg(i);
			dbg(mx[i]); dbg(mn[i]); dbg(add[i]); exit(0);
		}*/
		printf("%d\n", res);
	}
	
	return 0;
}