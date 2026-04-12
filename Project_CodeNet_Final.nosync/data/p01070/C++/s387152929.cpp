#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int MAX_LEN = 2500000;
int si[MAX_LEN], is[MAX_LEN], lcp[MAX_LEN];

void buildSA(const char *t){
	static int a[MAX_LEN], b[MAX_LEN];
	static pair<int, int> p[MAX_LEN];
	
	int n = strlen(t);
	
	rep(i, n + 1) is[i] = t[i], p[i] = make_pair(is[i], i);
	sort(p, p + n + 1);
	rep(i, n + 1) si[i] = p[i].second;
	
	for(int h = 0; ; ){
		rep(i, n){
			int x = si[i + 1], y = si[i];
			b[i + 1] = b[i];
			if(is[x] > is[y] || is[x + h] > is[y + h]) b[i + 1]++;
		}
		rep(i, n + 1) is[si[i]] = b[i];
		if(b[n] == n) break;
		h = max(1, h << 1);
		
		for(int k = h; k >= 0; k -= h){
			rep(i, n + 1) b[i] = 0;
			b[0] = k;
			
			for(int i = k; i <= n; i++) b[is[i]]++;
			rep(i, n) b[i + 1] += b[i];
			for(int i = n; i >= 0; i--)
				a[--b[si[i] + k > n ? 0 : is[si[i] + k]]] = si[i];
			
			swap(si, a);
		}
	}
}
void buildLCP(const char *t){
	int h = 0, n = strlen(t);
	
	rep(i, n + 1){
		if(is[i]){
			for(int j = si[is[i] - 1];
				j + h < n && i + h < n && t[j + h] == t[i + h]; h++);
			lcp[is[i]] = h;
		}
		else lcp[is[i]] = -1;
		if(h > 0) h--;
	}
}

//n?????????????????????+1
int *buildRMQ(int *a, int n){
	int logn = 1;
	for (int k = 1; k < n; k *= 2) ++logn;
	int *r = new int[n * logn];
	int *b = r;
	copy(a, a+n, b);
	for (int k = 1; k < n; k *= 2){
		copy(b, b + n, b + n); b += n;
		rep(i, n - k) b[i] = min(b[i], b[i+k]);
	}
	return r;
}
inline int minimum(int x, int y, int *rmq, int n){
	if(y <= x) return inf;
	if(x + 1 == y) return rmq[x];
	int z = --y - x, k = 31 - __builtin_clz(z);
	return min( rmq[x + n * k], rmq[y + n * k - (1 << k) + 1] );
}
int q, l[100000], r[100000];

struct RangeTree{
	vector<vi> dat;
	int n;
	RangeTree(int *a, int size){
		for(n = 1; n < size; n *= 2);
		dat.resize(2 * n - 1);
		init(a, size);
	}
	void init(int *a, int size){
		rep(i, size) dat[i + n - 1].pb(a[i]);
		for(int i = n - 2; i >= 0; i--){
			dat[i].resize(dat[i * 2 + 1].size() + dat[i * 2 + 2].size());
			merge(all(dat[i * 2 + 1]), all(dat[i * 2 + 2]), dat[i].begin());
		}
	}
	int query(int a, int b, int k, int l, int r, int v, int V){
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return lower_bound(all(dat[k]), V) - lower_bound(all(dat[k]), v);
		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2, v, V);
		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r, v, V);
		return vl + vr;
	}
	//[a, b)????????????[v, V)????????°
	int query(int a, int b, int v, int V){ return query(a, b, 0, 0, n, v, V); }
};

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	vi pos, len;
	string s;
	cin >> s >> q;
	rep(i, q){
		string m; cin >> l[i] >> r[i] >> m; r[i]++;
		s += '$'; pos.pb(s.size());
		s += m;   len.pb(m.size());
	}
	//dbg(s);
	//rep(i, q) dbg(s.substr(pos[i]));
	
	int n = s.size();
	buildSA(s.c_str());
	buildLCP(s.c_str());
	int *rmq = buildRMQ(lcp, n + 1);
	
	RangeTree S(si, n + 1);
	
	rep(i, q){
		int idx = is[pos[i]]; assert(si[idx] == pos[i]);
		int lo = 0, hi = idx, mid, L, R;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			if(minimum(mid + 1, idx + 1, rmq, n + 1) < len[i]) lo = mid;
			else hi = mid;
		}
		L = hi;
		
		lo = idx; hi = n + 1;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			if(minimum(idx + 1, mid + 1, rmq, n + 1) < len[i]) hi = mid;
			else lo = mid;
		}
		R = hi;
		
		//cerr<<"idx: "<<idx<<" L: "<<L<<" R: "<<R<<" min:"<<l[i]<<" max: "<<r[i] - len[i]+1<<endl;
		
		printf("%d\n", S.query(L, R, l[i], r[i] - len[i] + 1));
	}
	
	//rep(i, n+1)cerr<<i<<" "<<lcp[i]<<" "<<si[i]<<" "<<(i<=n?s.substr(si[i]):"")<<endl;
	
	return 0;
}