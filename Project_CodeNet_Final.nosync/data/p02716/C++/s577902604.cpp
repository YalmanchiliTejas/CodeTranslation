#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using Graph = std::vector<std::vector<int> >;
const int INF = 1e17;
/* libraries */

template <typename M>
struct SegmentTree
{
	const int n;
	const M I;
	const std::function<M(M,M)> f;
	std::vector<M> data;
	SegmentTree(int n, M I, std::function<M(M,M)> f) : n(n), data(2*n,I), I(I), f(f) {}
	void set(int i, const M& v) {
		data[n+i]=v;
	}
	void build() {
		for(int i=n-1;i>0;i--) {
			data[i]=f(data[i<<1],data[i<<1|1]);
		}
	}
	void update(int i, const M& v) {
		set(i,v);
		i+=n;
		for(i>>=1;i>0;i>>=1) {
			data[i]=f(data[i<<1],data[i<<1|1]);
		}
	}
	M get(int i) {
		return data[n+i];
	}
	M query(int l, int r) {
		M L=I, R=I;
		l+=n; r+=n;
		while(r>l) {
			if(l&1) L=f(L,data[l++]);
			if(r&1) R=f(data[--r],R);
			l>>=1; r>>=1;
		}
		return f(L,R);
	}
};


signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	// for n even
	std::vector<int> ac1(n+1,0), ac2(n+1,0);
	rep(i,n) {
		if(i%2==0) ac1[i+1]=ac1[i]+a[i];
		else ac1[i+1]=ac1[i];
	}
	std::reverse(all(a));
	rep(i,n) {
		if(i%2==n%2) ac2[i+1]=ac2[i]+a[i];
		else ac2[i+1]=ac2[i];
	}
	std::reverse(all(a));
	// range max segment tree
	SegmentTree<int> seg(n+1,-INF,[](int a, int b){return std::max(a,b);});
	rep(i,n+1) if(i%2==0) seg.set(i,ac1[i]+ac2[n-i]);
	seg.build();
	if(n%2==0) {
		print(seg.query(0,n+1));
		return 0;
	}
	auto rec = [&] (auto f, int r) -> int {
		if(r<2) return 0;
		int even = seg.query(0,r+1) - ac2[n-r];
		int odd = f(f,r-2) + a[r];
		debug(even,odd);
		return std::max(even, odd);
	};
	print(rec(rec,n-1));
	return 0;
}
