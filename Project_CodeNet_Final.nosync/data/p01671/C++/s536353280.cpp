#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long lint;
typedef pair< int, int > pii;

template< typename T >
void maxUpdate(T& a, T b) { a = max(a, b); }
template< typename T >
void minUpdate(T& a, T b) { a = min(a, b); }

class UnionFind {
private:
	vector< int > data;
	int num_of_g;
	
public:
	UnionFind(int n) : data(n, -1), num_of_g(n) {}
	
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		
		if (x == y) return 0;
		
		if (data[y] < data[x]) swap(x, y);
		data[x] += data[y]; data[y] = x;
		--num_of_g;
		
		return 1;
	}
	
	bool sameSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int getNumOfG() { return num_of_g; }
};

class HeavyLightDecomposition {
public:
	#define __HLD_WITH_STACK__
	
	struct Node {
		int parent;
		vector< int > path;
		vector< int > adj;
	};
	
	struct VertexInfo { int nodeID, pos; };
	
	struct Result {
		vector< Node > nodes;
		vector< VertexInfo > vinfo;
		
		int getNodeId(int v) { return vinfo[v].nodeID; }
		int getPathPos(int v) { return vinfo[v].pos; }
	};
	
private:
	int N;
	const vector< vector< int > >& adj;
	
	vector< Node > nodes;
	vector< VertexInfo > vinfo;
	vector< pii > part_max;
	
	int partDfs(int v, int p) {
		#ifndef __HLD_WITH_STACK__
		int part = 1;
		
		for (int u : adj[v]) {
			if (u != p) {
				int nxt = partDfs(u, v);
				maxUpdate(part_max[v], pii(nxt, u));
				part += nxt;
			}
		}
		
		return part;
		#else
		stack< pii > nst; nst.push(pii(v, p));
		stack< int > cst;
		
		while (!nst.empty()) {
			pii var = nst.top(); nst.pop();
			v = var.first; p = var.second;
			
			if (v < N) {
				nst.push(pii(v + N, p));
				cst.push(1);
				for (int u : adj[v]) if (u != p) nst.push(pii(u, v));
			} else if (p != -1) {
				int c = cst.top(); cst.pop();
				maxUpdate(part_max[p], pii(c, v - N));
				int nc = cst.top(); cst.pop();
				cst.push(c + nc);
			}
		}
		
		return cst.top();
		#endif
	}
	
	void decompDfs(int v, int p) {	
		#ifndef __HLD_WITH_STACK__	
		vinfo[v].nodeID = nodes.size() - 1;
		vinfo[v].pos = nodes[ nodes.size() - 1 ].path.size();
		
		nodes[ nodes.size() - 1 ].path.push_back(v);
		
		if (part_max[v].second != -1) {
			decompDfs(part_max[v].second, v);
			
			for (int u : adj[v]) {
				if (u != p && u != part_max[v].second) {
					nodes[ vinfo[v].nodeID ].adj.push_back(nodes.size());
					nodes.push_back(Node{v, vector< int >(), vector< int >()});
					
					decompDfs(u, v);
				}
			}
		}
		#else
		stack< pii > nst; nst.push(pii(v, p));
		stack< int > ist; ist.push(0);
		int max_id = 0;
		
		while (!nst.empty()) {
			pii var = nst.top(); nst.pop();
			int v = var.first, p = var.second;
			int nid = ist.top(); ist.pop();
			
			vinfo[v].nodeID = nid;
			vinfo[v].pos = nodes[nid].path.size();
			
			nodes[nid].path.push_back(v);
							
			if (part_max[v].second != -1) {
				nst.push(pii(part_max[v].second, v));
				ist.push(nid);
				
				for (int u : adj[v]) {
					if (u != p && u != part_max[v].second) {
						nodes[nid].adj.push_back(++max_id);
						nodes.push_back(Node{v, vector< int >(), vector< int >()});
						
						nst.push(pii(u, v));
						ist.push(max_id);
					}
				}
			}
		}
		#endif
	}
	
public:
	HeavyLightDecomposition(const vector< vector< int > >& _adj_) : N(_adj_.size()), adj(_adj_) {}
	
	Result decomposition(int root) {
		part_max.assign(N, pii(-1, -1));
		
		partDfs(root, -1);
		
		nodes.clear();
		nodes.push_back(Node{-1, vector< int >(), vector< int >()});
		
		vinfo = vector< VertexInfo >(N);
		
		decompDfs(root, -1);
		
		return Result{nodes, vinfo};
	}
};

class LowestCommonAncester {
public:
	#define __LCA_WITH_STACK__
	
	struct Result {
		vector< int > depth;
		
		int K;
		vector< vector< int > > parent;
		
		int getLCA(int u, int v) {
			if (depth[u] > depth[v]) swap(u, v);
			
			for_(k,0,K) if ((depth[v] - depth[u]) >> k & 1) v = parent[v][k];
			
			if (u == v) return u;
			
			for_rev(k,K-1,0) {
				if (parent[u][k] != parent[v][k]) {
					u = parent[u][k];
					v = parent[v][k];
				}
			}
			
			return parent[u][0];
		}
	};
	
private:
	int N;
	const vector< vector< int > >& adj;
	
	vector< int > depth;
	vector< vector< int > > parent;
	
	void depthDfs(int v, int p) {
		#ifndef __LCA_WITH_STACK__
		depth[v] = (p == -1) ? 0 : depth[p] + 1;
		parent[v][0] = p;
		for (int u : adj[v]) if (u != p) depthDfs(u, v);
		#else
		stack< pii > st;
		st.push(pii(v, p));
		
		while (!st.empty()) {
			pii var = st.top(); st.pop();
			v = var.first; p = var.second;
			
			parent[v][0] = p;
			depth[v] = (p == -1 ? 0 : depth[p] + 1);
			
			for (int u : adj[v]) if (u != p) st.push(pii(u, v));
		}
		#endif
	}
	
public:
	LowestCommonAncester(const vector< vector< int > >& _adj_) : N(_adj_.size()), adj(_adj_) {}
	
	Result generate(int root) {
		depth.assign(N, 0);
		
		int S = 1, K = 1;
		for (; S < N; S <<= 1) ++K;
		
		parent.assign(N, vector< int >(K, -1));
		
		depthDfs(root, -1);
		
		for_(k,0,K-1) for_(v,0,N) {
			if (parent[v][k] < 0) parent[v][k + 1] = -1;
			else parent[v][k + 1] = parent[ parent[v][k] ][k];
		}
		
		return Result{depth, K, parent};
	}
};

template< typename DATA >
class SegmentTreeLazy {
private:
	int size__;
	vector< DATA > data, lazy;
	
	inline int left_t(int k) { return (k << 1) + 1; }
	inline int right_t(int k) { return (k << 1) + 2; }
	inline int center(int l, int r) { return (l + r) >> 1; }
	
private:
	DATA calc(DATA d1, DATA d2) { return min(d1, d2); }
	
	void lazyCalc(int k, DATA val) { minUpdate(lazy[k], val); }
	
	inline void lazyEval(int l, int r, int k) {
		minUpdate(data[k], lazy[k]);
		
		if (k < size__ - 1) {
			lazyCalc(left_t(k), lazy[k]);
			lazyCalc(right_t(k), lazy[k]);
		}
		
		lazy[k] = DATA(1LL << 60);
	}
	
	inline void updateAt(int k) { data[k] = calc(data[left_t(k)], data[right_t(k)]); }
	
	void update(int a, int b, DATA x, int k, int l, int r) {
		lazyEval(l, r, k);
		
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazyCalc(k, x);
			lazyEval(l, r, k);
			return;
		}
		
		update(a, b, x, left_t(k), l, center(l, r));
		update(a, b, x, right_t(k), center(l, r), r);
		updateAt(k);
	}
	
	DATA query(int a, int b, int k, int l, int r) {
		lazyEval(l, r, k);
		
		if (r <= a || b <= l) return DATA(1LL << 60);
		if (a <= l && r <= b) return data[k];
		DATA res =  calc(query(a, b, left_t(k), l, center(l, r)),
						 query(a, b, right_t(k), center(l, r), r));
		
		updateAt(k);
		return res;
	}
	
public:
	SegmentTreeLazy() {}
	
	SegmentTreeLazy(int n, DATA ini, DATA lini) {
		for (size__ = 1; size__ < n; size__ <<= 1);
		data.assign(2 * size__ - 1, ini);
		lazy.assign(2 * size__ - 1, lini);
	}
	
	void update(int a, int b, DATA x) { update(a, b, x, 0, 0, size__); }
	
	DATA query(int a, int b) { return query(a, b, 0, 0, size__); }
	
	int size() { return size__; }
};

struct Edge {
	int id, u, v; lint c;
	bool operator < (const Edge& e) const { return c < e.c; }
};

int n, m;
vector< Edge > edges;

LowestCommonAncester::Result lca;
HeavyLightDecomposition::Result hld;
vector< SegmentTreeLazy< lint > > seg_vec;

void updateSegVec(int u, int w, lint c) {
	int cur_id = hld.getNodeId(u), end_id = hld.getNodeId(w);
	
	while (cur_id != end_id) {
		int pos = hld.getPathPos(u);
		seg_vec[cur_id].update(0, pos + 1, c);
		u = hld.nodes[cur_id].parent;
		cur_id = hld.getNodeId(u);
	}
	
	int w_pos = hld.getPathPos(w), u_pos = hld.getPathPos(u);
	seg_vec[end_id].update(w_pos + 1, u_pos + 1, c);
}

int main() {
	cin >> n >> m;
	
	for_(i,0,m) {
		int a, b; lint c;
		cin >> a >> b >> c;
		--a; --b;
		edges.emplace_back(Edge{i, a, b, c});
	}
	
	sort(edges.begin(), edges.end());
	
	lint min_cost = 0;
	vector< vector< int > > mst(n, vector< int >());
	vector< bool > used(m, false);
	UnionFind uf(n);
	
	for (Edge& e : edges) {
		if (uf.sameSet(e.u, e.v)) continue;
		uf.unionSet(e.u, e.v);
		mst[e.u].push_back(e.v);
		mst[e.v].push_back(e.u);
		used[e.id] = true;
		min_cost += e.c;
	}
	
	if (uf.getNumOfG() > 1) {
		for_(i,0,m) puts("-1");
		return 0;
	}
	
	lca = LowestCommonAncester(mst).generate(0);
	hld = HeavyLightDecomposition(mst).decomposition(0);
	
	int hldn = hld.nodes.size();
	
	for_(i,0,hldn) {
		seg_vec.emplace_back(SegmentTreeLazy< lint >(hld.nodes[i].path.size() + 1, 1LL << 60, 1LL << 60));
	}
	
	vector< lint > ans(m, -1);
	
	for (Edge& e : edges) {
		if (used[e.id]) continue;
		int w = lca.getLCA(e.u, e.v);
		updateSegVec(e.u, w, e.c);
		updateSegVec(e.v, w, e.c);
	}
	
	for (Edge& e : edges) {
		if (used[e.id]) {
			int u_nid = hld.getNodeId(e.u), v_nid = hld.getNodeId(e.v);
			
			if (u_nid == v_nid) {
				int u_pos = hld.getPathPos(e.u), v_pos = hld.getPathPos(e.v);
				ans[e.id] = min_cost - e.c + seg_vec[u_nid].query(min(u_pos , v_pos) + 1, max(u_pos, v_pos) + 1);
			} else {
				if (hld.nodes[v_nid].parent == e.u) {
					ans[e.id] = min_cost - e.c + seg_vec[v_nid].query(0, 1);
				} else {
					ans[e.id] = min_cost - e.c + seg_vec[u_nid].query(0, 1);
				}
			}
		} else {
			ans[e.id] = min_cost;
		}
	}
	
	for_(i,0,m) cout << (ans[i] >= 1LL << 60 ? -1 : ans[i]) << endl;
}