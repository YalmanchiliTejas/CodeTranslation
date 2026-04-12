#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename Monoid>
class SegmentTree {
	std::vector<Monoid> data;
	size_t sz;
	
	using F = std::function<Monoid(Monoid, Monoid)>;
	
	const F f;
	const Monoid E;
	
	public:
	SegmentTree(const size_t n, const F f, const Monoid E) : f(f), E(E) {
		sz = 1;
		while(sz < n) sz <<= 1;
		data.assign(sz << 1, E);
	}
	void set(int k, const Monoid x) {
		data[k + sz] = x;
	}
	void build() {
		for(int k = sz - 1; k > 0; k--) data[k] = f(data[2 * k + 0], data[2 * k + 1]);
	}
	void update(int k, const Monoid x) {
		k += sz;
		data[k] = f(data[k], x);
		
		while(k >>= 1) data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
	Monoid query(int a, int b) {
		Monoid L = E, R = E;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) L = f(L, data[a++]);
			if(b & 1) R = f(data[--b], R);
		}
		return f(L, R);
	}
	const Monoid operator[](const int k) const {
		return data[k + sz];
	}
};

int main() {
	int n; scanf("%d", &n); std::vector<int> a(n), vec;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]); vec = a;
	sort(begin(vec), end(vec)); vec.erase(unique(begin(vec), end(vec)), end(vec));
	
	SegmentTree<int> seg(n, [](int a, int b) { return a + b; }, 0);
	auto getIndex = [&seg, n](int p) {
		if(!seg.query(0, p)) return -1;
		int ok = 0, ng = p;
		while(std::abs(ok - ng) > 1) {
			int mid = (ok + ng) >> 1;
			
			if(seg.query(mid, p)) ok = mid;
			else ng = mid;
		}
		return ok;
	};
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int k = lower_bound(begin(vec), end(vec), a[i]) - begin(vec);
		int ret = getIndex(k);
		
		if(ret == -1) {
			seg.update(k, 1);
			ans++;
		} else {
			seg.update(ret, -1);
			seg.update(k, 1);
		}
		
	//	for(int i = 0; i < n; i++) cout << seg[i] << " "; cout << endl;
	}
	printf("%d\n", ans);
	return 0;
}
