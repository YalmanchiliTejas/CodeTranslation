#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
class Monoid {
public:
    using t1 = long;
    using t2 = long;

    static t1 id1() {
        return -1000000000000000;
    }
    static t2 id2() {
        return 0;
    }
    static t1 op1(const t1& l, const t1& r) {
        return max(l, r);
    }
    static t1 op2(const t1& l, const t2& r) {
        return r + l;
    }
    static t2 op3(const t2& l, const t2& r) {
        return r + l;
    }
};

template <typename M>
class LazySegmentTree {
    using T1 = typename M::t1;
    using T2 = typename M::t2;

private:
    const int h, n;
    vector<T1> data;
    vector<T2> lazy;

private:
	int ceillog2(int n_) {
        int res = 1;
		int c = 0;
        while (res < n_) {
			res <<= 1;
			c++;
		}
        return c;
    }
    void push(int node) {
        if (lazy[node] == M::id2()) return;
        if (node < n) {
            lazy[node * 2] = M::op3(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = M::op3(lazy[node * 2 + 1], lazy[node]);
        }
        data[node] = M::op2(data[node], lazy[node]);
        lazy[node] = M::id2();
    }
    void update(int node) {
        data[node] = M::op1(M::op2(data[node * 2], lazy[node * 2])
                        , M::op2(data[node * 2 + 1], lazy[node * 2 + 1]));
    }

public:
    LazySegmentTree(int n_)
        : h(ceillog2(n_)), n(1 << h), data(n * 2, M::id1()), lazy(n * 2, M::id2()) {}
    LazySegmentTree(int n_, T1 v1)
        : h(ceillog2(n_)), n(1 << h), data(n * 2, v1), lazy(n * 2, M::id2()) {}
    LazySegmentTree(const vector<T1>& data_)
        : h(ceillog2(data_.size())), n(1 << h), data(n * 2, M::id1()), lazy(n * 2, M::id2()) {
            init(data_);
    }
    void init() {
        for (int i = n - 1; i >= 1; i--) data[i] = M::op1(data[i * 2], data[i * 2 + 1]);
    }
    void init(const vector<T1>& data_) {
        for (int i = 0; i < (int)data_.size(); i++) data[i + n] = data_[i];
        init();
    }
    void update(int l, int r, T2 val) {
        l += n, r += n;
        for (int i = h; i > 0; i--) push(l >> i), push(r >> i);
        int tl = l, tr = r;
        r++;
        while (l < r) {
            if (l & 1) lazy[l] = M::op3(lazy[l], val), l++;
            if (r & 1) r--, lazy[r] = M::op3(lazy[r], val);
            l >>= 1; r >>= 1;
        }
        while (tl >>= 1, tr >>= 1, tl) {
            if (lazy[tl] == M::id2()) update(tl);
            if (lazy[tr] == M::id2()) update(tr);
        }
    }
	void update(int p, T1 val) {
        p += n;
        for (int i = h; i > 0; i--) push(p >> i);
		data[p] = val;
		lazy[p] = M::id2();
        while (p >>= 1, p) {
            update(p);
        }
    }
    T1 find(int l, int r) {
        l += n, r += n;
        for (int i = h; i > 0; i--) push(l >> i), push(r >> i);
        r++;
        T1 res1 = M::id1(), res2 = M::id1();
        while (l < r) {
            if (l & 1) res1 = M::op1(res1, M::op2(data[l], lazy[l])), l++;
            if (r & 1) r--, res2 = M::op1(M::op2(data[r], lazy[r]), res2);
            l >>= 1; r >>= 1;
        }
        return M::op1(res1, res2);
    }
};
pair<pair<int,int>,long> RL[200000];
void Calc(){
	int N = rei();
	int M = rei();
	long ans = 0;
	for(int i=0;i<M;i++){
		int l = rei()-1;
		int r = rei()-1;
		long a = rel();
		ans += a;
		RL[i] = {{r,l},-a};
	}
	sort(RL,RL+M);
	LazySegmentTree<Monoid> Seg(N+1);
	int p = 0;
	Seg.update(0,0);
	for(int i=0;i<N;i++){
		Seg.update(i+1,Seg.find(0,i));
		while(p < M && RL[p].first.first == i){
			int r = RL[p].first.first;
			int l = RL[p].first.second;
			long a = RL[p].second;
			p++;
			Seg.update(0,l,a);
		}
	}
	ans += Seg.find(0,N);
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}