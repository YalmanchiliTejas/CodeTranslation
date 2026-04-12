#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 4e5 + 5;

pii pp[MAXN];

pii vv[MAXN];

set<int> mins, maxs;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", &pp[i]._1, &pp[i]._2);
		if (pp[i]._1 > pp[i]._2) {
			swap(pp[i]._1, pp[i]._2);
		}
	}
	int mn1 = pp[0]._1, mx1 = pp[0]._1;
	int mn2 = pp[0]._2, mx2 = pp[0]._2;
	REP(i, 1, n) {
		mn1 = min(mn1, pp[i]._1);
		mx1 = max(mx1, pp[i]._1);
		mn2 = min(mn2, pp[i]._2);
		mx2 = max(mx2, pp[i]._2);
	}
	ll ans = 1ll * (mx1 - mn1) * (mx2 - mn2);
	
	REP(i, 0, n) {
		vv[2 * i] = mp(pp[i]._1, i);
		vv[2 * i + 1] = mp(pp[i]._2, i);
	}
	sort(vv, vv + 2 * n);
	if (vv[0]._2 == vv[2 * n - 1]._2) {
		printf("%lld\n", ans);
		return;
	}
	
	//printf("%lld\n", ans);
	
	int l, r;
	for(r = 2 * n - 1; r >= 0; r--) {
		if (maxs.find(vv[r]._2) != maxs.end()) {
			break;
		}
		maxs.insert(vv[r]._2);
	}
	for(l = 0; l < 2 * n; l++) {
		if (maxs.find(vv[l]._2) != maxs.end() || mins.find(vv[l]._2) != mins.end()) {
			break;
		}
		mins.insert(vv[l]._2);
	}
	mn1 = vv[0]._1, mx1 = vv[2 * n - 1]._1;
	for(; ; ) {
		mn2 = vv[l]._1;
		mx2 = vv[r]._1;
		ans = min(ans, 1ll * (mx1 - mn1) * (mx2 - mn2));
		
		//printf("%d %d\n", mn2, mx2);
		
		if (mins.find(vv[l]._2) != mins.end() || vv[l]._2 == vv[2 * n - 1]._2) {
			break;
		}
		if (maxs.find(vv[l]._2) != maxs.end()) {
			for(; r < 2 * n && vv[r]._2 != vv[l]._2; r++) {
				maxs.erase(vv[r]._2);
			}
			maxs.erase(vv[l]._2);
		}
		mins.insert(vv[l]._2);
		l++;
	}
	
	printf("%lld\n", ans);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
