#include <bits/stdc++.h>
using namespace std;
#define li          long
#define ll          long long
#define ull         unsigned long long
#define ff          first
#define ss          second
#define pii         pair<int,int>
#define pli         pair<li,li>
#define pll         pair<ll,ll>
#define pb          push_back
#define fo(i,k,n)   for(int i = k;i<n; i++)
#define ro(i,k,n)   for(int i = k; i>=n; i--)
#define tc          int t;cin>>t;while(t--)
#define all(v)      v.begin(),v.end()
#define inf         INT_MAX
#define ninf        INT_MIN
#define v(x)        vector<x>
#define int         long long
#define ar(x,y)     array<x,y>
const ll mod1 = 99844353;
const ll mod2 = 1e9+7;
/* template <class T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; */

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int power(int x,int y){
	int res = 1;
	while(y > 0){
	 	if(y & 1) res *= x;
	 	y >>= 1;
	 	x *= x;
	}
	return res;
}

int power(int x,int y,int mod){
 	int res = 1;
 	x %= mod;
 	while(y > 0){
 	 	if(y & 1) res = (res * x) % mod;
 	 	y >>= 1;
 	 	x = (x * x) % mod;
 	}
 	return res;
}

struct dsu{
  unordered_map<int,int> pr,sz;
  dsu(){
    (this->pr).clear();
    (this->sz).clear();
  }
  void make(int x){
    pr[x] = x;
    sz[x] = 1;
  }
  int getpar(int x){
    if(pr[x] == x)return x;
    return pr[x] = getpar(pr[x]);
  }
  void merge(int x,int y){
    x = getpar(x);
    y = getpar(y);
    if(sz[x]<sz[y])swap(x,y);
    pr[y] = x;
    sz[x]+=sz[y];
    sz[y] = 0;
  }
};

class data {
	public:
	int sum,pref,suff,ans;
	data(int val){
	 	this -> sum = val;
   		this -> pref = this -> suff = this -> ans = max(0ll, val);
	}
	data(){}
	data combine(data l,data r){
	 	data res;
    	res.sum = l.sum + r.sum;
    	res.pref = max(l.pref, l.sum + r.pref);
    	res.suff = max(r.suff, r.sum + l.suff);
    	res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    	return res;
	}
};

class Seg_Tree : public data {
	public :
	int n;
	vector<data> t;
	Seg_Tree(int cap){
	 	this -> n = cap;
	 	(this -> t).resize(4*n);
	}

	void build(vector<int> &a, int v, int tl, int tr) {
    	if (tl == tr) {
        	t[v] = data(a[tl]);
    	} else {
        	int tm = (tl + tr) / 2;
        	build(a, v*2, tl, tm);
        	build(a, v*2+1, tm+1, tr);
        	t[v] = combine(t[v*2], t[v*2+1]);
    	}
	}
	
	void update(int v, int tl, int tr, int pos, int new_val) {
    	if (tl == tr) {
        	t[v] = data(new_val);
    	} else {
        	int tm = (tl + tr) / 2;
        	if (pos <= tm)
            	update(v*2, tl, tm, pos, new_val);
        	else
            	update(v*2+1, tm+1, tr, pos, new_val);
        	t[v] = combine(t[v*2], t[v*2+1]);
    	}
	}   	
	data query(int v, int tl, int tr, int l, int r) {
    	if (l > r) 
        	return data(0);
    	if (l == tl && r == tr) 
        	return t[v];
    	int tm = (tl + tr) / 2;
    	return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
};

class LCA {
	public:
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

class Bit_Tree {
	public :
    vector<int> bit;  
    int n;

    Bit_Tree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    Bit_Tree(vector<int> a)
        : Bit_Tree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};


class Template {
    
 public:
    void solveOne(istream &in, ostream &out) {
    	int n;
	in >> n;
	v(int) a(n);
	int mod = 1e9+7;
	fo(i,0,n)
		in >> a[i];
	v(int) PrefixSum(n,0);
	PrefixSum[0] = a[0]%mod;
	for(int i = 1; i<n; i++){
		PrefixSum[i] = (PrefixSum[i-1] + a[i])%mod;
	}
	int ans = 0;
	for(int i = 0; i<n-1; i++){
		ans = (ans + (a[i]*((PrefixSum[n-1]-PrefixSum[i])%mod+mod)%mod)%mod)%mod;
	}
	out << ans << "\n";
    }
    
    void solve(istream &in, ostream &out) {
        int nt = 1;
        //in >> nt;
        for (int it = 0; it < nt; ++it) {
            solveOne(in, out);
        }
    }
};
 
 
signed main() {
  fastio();
  Template solver;
  istream& in(cin);
  ostream& out(cout);
  solver.solve(in, out);
  return 0;
}
