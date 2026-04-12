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

using cost_type = s64;
#define COST_INF (LINF)
typedef struct Edge {
	int from;
	int to;
	cost_type cost;
	size_t next;
	bool operator<(const struct Edge& a) const { return cost < a.cost; }
} Edge;
struct Graph {
	int n;
	vector<Edge> hen;
	vector<size_t> head;
	
	// result of Warshall–Floyd
	vector<vector<cost_type> > WF;
	bool wf_completed = false;
	// result of dijkstra and Bellman-Ford/SPFA
	vector<vector<cost_type> > SSSP;
	set<int> sssp_completed;
	// result of dfs(reachable check)
	vector<vector<bool> > DFS;
	set<int> dfs_completed;
	
	Graph(int n) { // O(N)
		head.resize(n);
		SSSP.resize(n);
		DFS.resize(n);
		this->n = n;
	}
	cost_type kruskal() {
		vector<Edge> hen_all = hen;
		sort(all(hen_all));
		
		int num = 0;
	    UnionFind uni(n);
	    cost_type res = 0;
		for (auto& i : hen_all) {
			if (!uni.find(i.from, i.to)) {
				res += i.cost;
				uni.unite(i.from, i.to);
				if (++num >= n-1) return res;
			}
		}
		return res;
	}
	int spfa(int k) {
		vector<bool> inque(n,false);
		vector<int> updated(n,0);
		sssp_completed.insert(k);
		SSSP[k].assign(n,COST_INF);
		SSSP[k][k] = 0;
		queue<int> que; inque[k] = true; que.push(k);
		while (que.size()) {
			int i = que.front(); que.pop();
			for (size_t j = head[i]; ~j; j=hen[j].next) {
				if (SSSP[k][hen[j].to] > SSSP[k][i] + hen[j].cost) {
					SSSP[k][hen[j].to] = SSSP[k][i] + hen[j].cost;
					if (++updated[hen[j].to] > n) return hen[j].to;
					if (!inque[hen[j].to]) {
						inque[hen[j].to] = true;
						que.push(hen[j].to);
					}
				}
			}
			inque[i] = false;
		}
		return -1;
	}
	void dij(int k) { // O(n+mlogm)
		sssp_completed.insert(k);
		SSSP[k].assign(n,COST_INF);
		SSSP[k][k] = 0;
		using State = pair<cost_type, int>;
		priority_queue<State, vector<State>, greater<State> > que;
		que.push({0,k});
		while(que.size()) {
			auto i = que.top(); que.pop();
			for (size_t j = head[i.se]; ~j; j=hen[j].next) {
				if (SSSP[k][hen[j].to] > i.fi + hen[j].cost) {
					SSSP[k][hen[j].to] = i.fi + hen[j].cost;
					que.push({SSSP[k][hen[j].to], hen[j].to});
				}
			}
		}
	}
	
	void wf() { // O(n^3)
		WF.assign(n,vector<cost_type>(n,COST_INF));
		FOR(i,n) {
			WF[i][i] = 0;
			for (size_t j = head[i]; ~j; j=hen[j].next)
				WF[i][hen[j].to] = hen[j].cost;
		}
		FOR(k,n) {
			FOR(i,n) {
				FOR(j,n) {
					if (WF[i][k] != COST_INF && WF[k][j] != COST_INF) {
						WF[i][j] = min(WF[i][j], WF[i][k] + WF[k][j]);
					}
				}
			}
		}
		wf_completed = true;
	}
	
	void dfs(int from) { // O(N+M)
		DFS[from].assign(n,false);
		DFS[from][from] = true;
		queue<int> que; que.push(from);
		while(que.size()) {
			int i = que.front(); que.pop();
			for (size_t j = head[i]; ~j; j=hen[j].next) {
				if (!DFS[from][hen[j].to]) {
					DFS[from][hen[j].to] = true;
					que.push(hen[j].to);
				}
			}
		}
		dfs_completed.insert(from);
	}
	inline bool reachable(int from, int to) {
		assert(dfs_completed.count(from));
		return DFS[from][to];
	}
	inline pair<bool,cost_type> shortest(int from, int to) {
		assert(wf_completed || sssp_completed.count(from));
		if (wf_completed)
			return mp(WF[from][to] != COST_INF, WF[from][to]);
		else if (sssp_completed.count(from))
			return mp(SSSP[from][to] != COST_INF, SSSP[from][to]);
		else return {}; // should not reached
	}
	inline void add_hen(int from, int to, cost_type cost, bool muki) {
		insert_hen(from,to,cost);
		if (!muki) insert_hen(to, from, cost);
	}
	private:inline void insert_hen(int from, int to, cost_type cost) {
		Edge new_edge = {from, to, cost, (size_t)-1};
		size_t id = hen.size();
		hen.push_back(new_edge);
		hen[head[from]].next = id;
		head[from] = id;
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
	
	cost_type res = graph.kruskal();
	
	cout << res << endl;
	
    return 0;
}
