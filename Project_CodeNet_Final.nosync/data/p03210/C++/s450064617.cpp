#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

class UnionFind{
private:
	std::vector<int_fast32_t> par;
	size_t n;

public:
	UnionFind(){}
	UnionFind(size_t n):n(n){
		par.resize(n, -1);
	}

	uint_fast32_t find(uint_fast32_t x){
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}

	size_t size(uint_fast32_t x){
		return -par[find(x)];
	}

	void unite(uint_fast32_t x, uint_fast32_t y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(size(x) < size(y)) std::swap(x, y);
		par[x] += par[y];
		par[y] = x;
	}

	bool same(uint_fast32_t x, uint_fast32_t y){
		return find(x) == find(y);
	}
};

const int64 mod = 1e9+7;

int main(void){
	int32 x;
	cin >> x;
	if(x == 3 || x == 5 || x == 7){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
