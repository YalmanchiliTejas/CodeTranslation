#include <bits/stdc++.h>
using namespace std;

#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define exit(a, b) return cout << a, b;

#define PB push_back
#define MP make_pair

#define sd(n) scanf("%lld", &n)
#define pdn(n) printf("%lld\n", n);
#define pds(n) printf("%lld ", n);
#define endl '\n'

#define forn(a, b, i) for (int i = a; i < b; i += 1)
#define all(v) v.begin(), v.end() 

using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define print(stuff) cout << stuff << endl
#define len(stuff) stuff.size()

#define int long long

const int upper = 1e5 + 20;
const int M = (int) 1e9 + 7;
const int inf = (int) 1e17;
const double eps =  1e-8;

vector<vi> adj;
int score[1001][1001];
vector<int> perm, position, indeg;

vector<int> status;

int n, k;

bool cycle = false;

void dfs (int current) {
	status[current] = 1;
	for (auto v: adj[current]) {
		if (status[v] == 2) continue;
		if (status[v] == 1) {
			cycle = true;
			return;
		}

		dfs(v);
	}
	status[current] = 2;
}

signed main () {
	start_routine();
	speed();
	#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);	
	// freopen("output.txt", "w", stdout);
	// freopen("errlog.txt", "w", stderr);
	#endif		

	int x; cin >> x;
	if (x == 3 || x == 5 || x == 7) {
		cout << "YES";
	} else cout << "NO";	
 	end_routine();	
}