#include <bits/stdc++.h>

using namespace std;

#define countof(a) (sizeof(a)/sizeof(*a))

#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pi >
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define all(n) n.begin(), n.end()

#define FROMTO(var, from, to) for (register int var = (from), var##down = ((int)(to)) < ((int)(from));var##down ? (var >= (int)(to)) : (var <= (int)(to));var##down ? var-- : var++)
#define UPTO(var, from, to)   for (register int var = (from); var <= ((int)to); var++)
#define DOWNTO(var, from, to) for (register int var = (from); var >= ((int)to); var--)
#define FOR(var, to)          UPTO(var, 0, (to)-1)
#define DOWN(var, from)       DOWNTO(var, (from)-1, 0) 

#define INIT(var, val) FOR(i,countof(var)) var[i] = val
#define INPUT(var) FOR(i,countof(var)) cin >> var[i]
#define INPUT1(var) FOR(i,countof(var)) cin >> var[i], var[i]--

#define SORT(v) qsort(v,countof(v),sizeof(*v),int_less)
#define SORTT(v) qsort(v,countof(v),sizeof(*v),int_greater)
#define QSORT(v,b) qsort(v,countof(v),sizeof(*v),b)

#define MOD 1000000007
#define INF ((1 << 30)-1)
#define LINF ((1LL << 62)-1)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

struct Comb {
    vector<vector<s64> > data;
    Comb(int n) { // O(n^2)
        data = vector<vector<s64> >(n+1,vector<s64>(n+1,1));
        UPTO(i,1,n) {
            FOR(j,i+1) {
                if (!j || j == i) data[i][j] = 1;
                else data[i][j] = data[i-1][j-1] + data[i-1][j];
            }
        }
    }
    
    s64 ncr(int n, int r) {
        return data[n][r];
    }
};

static inline int ri() {
  int a;
  scanf("%d", &a);
  return a;
}

int int_less(const void *a, const void *b) {
  return (*((const int*)a) - *((const int*)b));
}
int int_greater(const void *a, const void *b) {
  return (*((const int*)b) - *((const int*)a));
}

struct Graph {
	int n;
	vector<vector<pair<int, s64> > > hen;
	
	// result of Warshall–Floyd
	vector<vector<s64> > WF;
	bool wf_complete = false;
	
	// result of dijkstra
	vector<vector<s64> > DIJ;
	set<int> dij_completed;
	
	// result of Bellman–Ford
	vector<vector<s64> > BF;
	set<int> bf_completed;
	
	// result of dfs(reachable check)
	vector<vector<bool> > DFS;
	set<int> dfs_completed;
	
	Graph(int n) { // O(N)
		hen.resize(n, vector<pair<int, s64> >());
		DIJ.resize(n, vector<s64>());
		BF.resize(n, vector<s64>());
		DFS.resize(n, vector<bool>());
		this->n = n;
	}
	
	// return the position of negative cycle(-1 if none)
	int bf(int k) {
		bf_completed.insert(k);
		BF[k].resize(n,LINF);
		BF[k][k] = 0;
		FOR(i,n-1) {
			bool updated = false;
			FOR(j,n) {
				for (auto l : hen[j]) {
					if (BF[k][j] != LINF && BF[k][l.fi] > BF[k][j] + l.se)
						BF[k][l.fi] = BF[k][j] + l.se, updated = true;
				}
			}
			if (!updated) break;
		}
		
		FOR(j,n) {
			for (auto l : hen[j]) {
				if (BF[k][j] != LINF && BF[k][l.fi] > BF[k][j] + l.se) {
					return j; // negative loop
				}
			}
		}
		return -1;
	}
	int spfa(int k) {
		vector<bool> inque(n,false);
		vector<int> updated(n,0);
		
		bf_completed.insert(k);
		BF[k].resize(n,LINF);
		BF[k][k] = 0;
		
		queue<int> que;
		inque[k] = true;
		que.push(k);
		updated[k]++;
		while (que.size()) {
			int i = que.front(); que.pop();
			for (auto j : hen[i]) {
				if (BF[k][j.fi] > BF[k][i] + j.se) {
					BF[k][j.fi] = BF[k][i] + j.se;
					updated[j.fi]++;
					if (updated[j.fi] > n) return j.fi;
					if (!inque[j.fi]) {
						inque[j.fi] = true;
						que.push(j.fi);
					}
				}
			}
			inque[i] = false;
		}
		return -1;
	}
	
	int dij(int k) { // O(n+mlogm)
	    clock_t start = clock();
		assert(dij_completed.count(k) == 0);
			dij_completed.insert(k);
		vector<int> updated(n,0);
		DIJ[k].resize(n,LINF);
		DIJ[k][k] = 0;
		priority_queue<pair<s64, int>, vector<pair<s64, int> >, greater<pair<s64,int> > > que;
		que.push(pair<s64,int>(0,k));
		while(que.size()) {
			auto i = que.top(); que.pop();
			for (auto j : hen[i.se]) {
				if (DIJ[k][j.fi] > i.fi + j.se) {
					DIJ[k][j.fi] = i.fi + j.se;
					que.push(pair<s64,int>(DIJ[k][j.fi], j.fi));
					updated[j.fi]++;
					if (updated[j.fi] % 300 == 0) {
					    if ((double)(clock()-start)/CLOCKS_PER_SEC>1.9 || que.size() > 10000000) return j.fi;
					}
				}
			}
		}
		return -1;
	}
	
	void wf() { // O(n^3)
		WF.resize(n, vector<s64>(n,LINF));
		FOR(i,n) {
			WF[i][i] = 0;
			for (auto j : hen[i]) {
				WF[i][j.fi] = j.se;
			}
		}
		FOR(k,n) {
			FOR(i,n) {
				FOR(j,n) {
					if (WF[i][k] != LINF && WF[k][j] != LINF) {
						WF[i][j] = min(WF[i][j], WF[i][k] + WF[k][j]);
					}
				}
			}
		}
		wf_complete = true;
	}
	
	void dfs(int from) {
		DFS[from].resize(n, false);
		DFS[from][from] = true;
		queue<int> que; que.push(from);
		while(que.size()) {
			auto i = que.front(); que.pop();
			for (auto j : hen[i]) {
				if (!DFS[from][j.fi]) {
					DFS[from][j.fi] = true;
					que.push(j.fi);
				}
			}
		}
		dfs_completed.insert(from);
	}
	
	bool reachable(int from, int to) {
		assert(dfs_completed.count(from));
		return DFS[from][to];
	}
	
	pair<bool,s64> shortest(int from, int to) {
		assert(wf_complete || dij_completed.count(from) || bf_completed.count(from));
		if (wf_complete)
			return mp(WF[from][to] != LINF, WF[from][to]);
		else if (dij_completed.count(from))
			return mp(DIJ[from][to] != LINF, DIJ[from][to]);
		else if (bf_completed.count(from))
			return mp(BF[from][to] != LINF, BF[from][to]);
		else return {}; // should not reached
	}
	
	void add_hen(int from, int to, s64 cost, bool muki) {
		hen[from].push_back(mp(to, cost));
		if (!muki) hen[to].push_back(mp(from, cost));
	}
};
// Graph.dfs : O(N)
// Graph.dij : O(N+MlogM)
// Graph.bf  : O(NM)
// Graph.wf  : O(N^3)
// Graph.reachable
// Graph.shortest

int n,m;
vvi a;

int res(int cur, int state) {
    if (state == (1<<n)-1) return 1;
    int ret = 0;
    for (auto i : a[cur]) {
        if ((state>>i)&1) continue;
        ret += res(i, state | (1<<i));
    }
    return ret;
}

int main() {
    n = ri();
    m = ri();
    a.resize(n);
    FOR(i,m) {
        int aa = ri()-1;
        int bb = ri()-1;
        a[aa].push_back(bb);
        a[bb].push_back(aa);
    }
    
    cout << res(0, 1) << endl;

    // cout << res << endl;
    return 0;
}
