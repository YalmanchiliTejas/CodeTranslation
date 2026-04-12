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
const int INF = 1e9 + 55;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

pii pp[MAXN];

set<pii> px, py;

set<pii> st;

int dis[MAXN];

int used[MAXN];

void upd_set(int ind, int new_dis) {
	if (!used[ind] && dis[ind] > new_dis) {
		st.erase(mp(dis[ind], ind));
		dis[ind] = new_dis;
		st.insert(mp(dis[ind], ind));
	}
}

void process_coord(set<pii> &ps, int ind, int coord) {
	set<pii>::iterator it = ps.find(mp(coord, ind));
	set<pii>::iterator it1 = it;
	it1++;
	
	if (it1 != ps.end()) {
		int to = it1->_2;
		upd_set(to, it1->_1 - it->_1);
	}
	
	if (it != ps.begin()) {
		int old_v = it->_1;
		it--;
		int to = it->_2;
		upd_set(to, old_v - it->_1);
	}
	
	ps.erase(mp(coord, ind));
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", &pp[i]._1, &pp[i]._2);
		px.insert(mp(pp[i]._1, i));
		py.insert(mp(pp[i]._2, i));
	}
	REP(i, 0, n) {
		if (i > 0) {
			dis[i] = INF;
		}
		st.insert(mp(dis[i], i));
	}
	ll ans = 0ll;
	while(!st.empty()) {
		int ind = st.begin()->_2;
		ans += st.begin()->_1;
		st.erase(st.begin());
		used[ind] = 1;
		
		process_coord(px, ind, pp[ind]._1);
		process_coord(py, ind, pp[ind]._2);
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
