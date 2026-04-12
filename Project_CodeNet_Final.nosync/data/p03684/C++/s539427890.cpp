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


struct UnionFind{
    vi data;
    UnionFind(int size):data(size,-1){}
    bool unite(int x,int y) {
        x=root(x);y=root(y);
        if(x!=y){
            if(data[y]<data[x])swap(x,y);
            data[x]+=data[y];data[y]=x;
        }
        return x!=y;
    }
    bool find(int x,int y) {
        return root(x)==root(y);
    }
    int root(int x) {
        return data[x]<0?x:data[x]=root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
    // added by QCFium
    bool united() {
        int comroot = -1;
        FOR(i,data.size()) {
            if (comroot != -1 && root(i) != comroot) return false;
            comroot = root(i);
        }
        return true;
    }
};


struct Graph {
	int n;
	vector<vector<pair<int, s64> > > hen;
	
	vector<pair<s64, pair<int,int> > > hen_s;
	
	// result of Warshall–Floyd
	vector<vector<s64> > WF;
	bool wf_completed = false;
	
	// result of dijkstra and Bellman-Ford/SPFA
	vector<vector<s64> > SSSP;
	set<int> sssp_completed;
	
	// result of dfs(reachable check)
	vector<vector<bool> > DFS;
	set<int> dfs_completed;
	
	Graph(int n) { // O(N)
		hen.resize(n, vector<pair<int, s64> >());
		SSSP.resize(n, vector<s64>());
		DFS.resize(n, vector<bool>());
		this->n = n;
	}
	
	s64 kruskal() {
		if (!hen_s.size()) {
			FOR(i,n) {
				int t;
				for (auto& j : hen[i]) {
					hen_s.push_back({j.se,{t=i,j.fi}});
				}
			}
			sort(all(hen_s));
		}
		
	    UnionFind uni(n);
	    s64 res = 0;

	    FOR(i, hen_s.size()) {
	      auto& e = hen_s[i];
	      if (!uni.find(e.se.fi, e.se.se)) {
	        // 辺を追加しても閉路ができないなら、その辺を採用する
	        res += e.fi;
	        uni.unite(e.se.fi, e.se.se);
	      }
	    }
		return res;
	}
	
	// return the position of negative cycle(-1 if none)
	int bf(int k) {
		sssp_completed.insert(k);
		SSSP[k].resize(n,LINF);
		SSSP[k][k] = 0;
		FOR(i,n-1) {
			bool updated = false;
			FOR(j,n) {
				for (auto l : hen[j]) {
					if (SSSP[k][j] != LINF && SSSP[k][l.fi] > SSSP[k][j] + l.se)
						SSSP[k][l.fi] = SSSP[k][j] + l.se, updated = true;
				}
			}
			if (!updated) break;
		}
		
		FOR(j,n) {
			for (auto l : hen[j]) {
				if (SSSP[k][j] != LINF && SSSP[k][l.fi] > SSSP[k][j] + l.se) {
					return j; // negative loop
				}
			}
		}
		return -1;
	}
	
	int spfa(int k) {
		vector<bool> inque(n,false);
		vector<int> updated(n,0);
		
		sssp_completed.insert(k);
		SSSP[k].resize(n,LINF);
		SSSP[k][k] = 0;
		
		queue<int> que; inque[k] = true;que.push(k);
		while (que.size()) {
			int i = que.front(); que.pop();
			for (auto j : hen[i]) {
				if (SSSP[k][j.fi] > SSSP[k][i] + j.se) {
					SSSP[k][j.fi] = SSSP[k][i] + j.se;
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
	
	void dij(int k) { // O(n+mlogm)
		SSSP[k].resize(n);
		fill(all(SSSP[k]), LINF);
		SSSP[k][k] = 0;
		priority_queue<pair<s64, int>, vector<pair<s64, int> >, greater<pair<s64,int> > > que;
		que.push(pair<s64,int>(0,k));
		while(que.size()) {
			auto i = que.top(); que.pop();
			for (auto j : hen[i.se]) {
				if (SSSP[k][j.fi] > i.fi + j.se) {
					SSSP[k][j.fi] = i.fi + j.se;
					que.push(pair<s64,int>(SSSP[k][j.fi], j.fi));
				}
			}
		}
		sssp_completed.insert(k);
	}
	
	void wf() { // O(n^3)
		WF.resize(n);
		fill(all(WF), vector<s64>(n,LINF));
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
		wf_completed = true;
	}
	
	void dfs(int from) { // O(N+M)
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
		assert(wf_completed || sssp_completed.count(from));
		if (wf_completed)
			return mp(WF[from][to] != LINF, WF[from][to]);
		else if (sssp_completed.count(from))
			return mp(SSSP[from][to] != LINF, SSSP[from][to]);
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
// Graph.spfa: O(NM) faster
// Graph.wf  : O(N^3)
// Graph.reachable
// Graph.shortest

typedef struct {
	int x;
	int y;
	int id;
} Dot;

int dot_less_x(const void *a, const void *b) {
	return (((const Dot*)b)->x - ((const Dot*)a)->x);
}
int dot_less_y(const void *a, const void *b) {
	return (((const Dot*)b)->y - ((const Dot*)a)->y);
}

int main() {
	int n = ri();
	Dot a[n];
	FOR(i,n) {
		int t = ri();
		a[i] = {t, ri(), i};
	}
	
	Graph graph(n);
	QSORT(a,dot_less_x);
	FOR(i,n-1) {
		graph.add_hen(a[i].id, a[i+1].id, abs(a[i].x-a[i+1].x), false);
	}
	QSORT(a,dot_less_y);
	FOR(i,n-1) {
		graph.add_hen(a[i].id, a[i+1].id, abs(a[i].y-a[i+1].y), false);
	}
	
	s64 res = graph.kruskal();
	
	cout << res << endl;
	
    return 0;
}
