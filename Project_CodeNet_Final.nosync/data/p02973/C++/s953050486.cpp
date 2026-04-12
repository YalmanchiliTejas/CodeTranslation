//This is getting accepted!
#include<bits/stdc++.h>
#define ll long long
#define oo 1000000009
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define INA(a,n) for (int i = 1; i <= (n); ++i) cin >> a[i];
#define ITE(x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define isset(x, i) (((x)>>(i))&1)
#define setbit(x, i) ((x)^(1ll<<(i)))
#define clearbit(x, i) ((x)&(~(1ll<<(i))))
#define twoexp(i) (1ll<<(i))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define FI first
#define SE second
#define son1 (id*2)
#define son2 (id*2+1)

using namespace std;

const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 2 * acos(0);
const int MAXN = 1e6 + 6;

int n;
multiset<int> bag, tmp;
int a[MAXN], indexx[MAXN];

void input() {
	int u, v, w, x, y, qtype;
	
	cin >> n;
	INA(a, n);
	
}

bool cmp(int u, int v) {
	return a[u] > a[v];
}


void preprocess() {
	
	FOR(i, 1, n)
		indexx[i] = i;
	
	sort(indexx+1, indexx+n+1, cmp);
	
	FOR(i, 1, n) {
		int id_l = i;
		while(i+1 <= n && a[indexx[i+1]] == a[indexx[i]]) {
			i++;
		}
		int id_r = i;
		
		vector<int> idx;
		FOR(id, id_l, id_r)
			idx.push_back(indexx[id]);
		sort(idx.begin(), idx.end());
		
		tmp.clear();
		for (int ii = idx.size()-1; ii >= 0; --ii) {
			int id = idx[ii];
			
			auto pt = bag.upper_bound(id);
			if (pt != bag.end()) {
				bag.erase(pt);
			}
			tmp.insert(id);
			
		}
		
		ITE(tmp) {
			bag.insert(*it);
		}
		
	}
	
	cout << bag.size() << "\n";
	
}

void process(int itest) {
	int u, v, w, x, y, qtype;
	
	
	
}

void oneTest() {
	
	input();
	preprocess();
	process(0);
	
}

void multiTest() {
	
	int t;
	cin >> t;
	
	for (int it = 1; it <= t; ++it) {
		input();
		preprocess();
		process(it);
	}
}

int main(){
    #ifndef ONLINE_JUDGE
//    freopen("../out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	oneTest();
//	multiTest();

    return 0;

}
