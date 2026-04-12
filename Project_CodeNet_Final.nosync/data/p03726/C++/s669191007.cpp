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

const int MAXN = 1e5 + 5;

set<int> g[MAXN];
map<int, int> leafs;
set<int> pars;

void solve(){
	int n, a, b;
	scanf("%d", &n);
	REP(i, 1, n) {
		scanf("%d%d", &a, &b);
		g[a].insert(b);
		g[b].insert(a);
	}
	REPN(i, 1, n) {
		if (SZ(g[i]) == 1) {
			int par = *g[i].begin();
			if (leafs.find(par) != leafs.end()) {
				printf("First\n");
				return;
			}
			leafs[par] = i;
			if (SZ(g[par]) == 2) {
				pars.insert(par);
			}
		}
	}
	int cur_cnt = n;
	while(1) {
		if (cur_cnt == 1 || cur_cnt == 3) {
			printf("First\n");
			return;
		}
		if (cur_cnt == 2) {
			printf("Second\n");
			return;
		}
		cur_cnt -= 2;
		int par = *pars.begin();
		int leaf = leafs[par];
		
		leafs.erase(par);
		pars.erase(par);
		g[leaf].clear();
		g[par].erase(leaf);
		
		int parpar = *g[par].begin();
		g[par].clear();
		g[parpar].erase(par);
		
		if (SZ(g[parpar]) == 1) {
			int parparpar = *g[parpar].begin();
			if (leafs.find(parparpar) != leafs.end()) {
				printf("First\n");
				return;
			}
			leafs[parparpar] = parpar;
			if (SZ(g[parparpar]) == 2) {
				pars.insert(parparpar);
			}
		} else if (leafs.find(parpar) != leafs.end() && SZ(g[parpar]) == 2) {
			pars.insert(parpar);
		}
	}
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
