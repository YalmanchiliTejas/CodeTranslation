#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

struct UnionFind{
	vector<int> elems;
	UnionFind(int n):elems(n){
		for(int i=0;i<n;i++){
			elems[i] = i;
		}
	}
	bool same(int a, int b){
		return parent(a) == parent(b);
	}
	void unite(int a, int b){
		elems[parent(a)] = parent(b);
	}
private:
	int parent(int a){
		if(a == elems[a]){
			return a;
		}
		return elems[a] = parent(elems[a]);
	}
};

int main(){
    int n; cin >> n;
    vector<pair<int, int>> xs(n), ys(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        xs[i] = {x, i};
        ys[i] = {y, i};
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    struct Elem{
        int len, a, b;
        bool operator < (const Elem& e) const{
            return len < e.len;
        }
    };
    vector<Elem> ve;
    for(int i = 1; i < n; i++){
        ve.push_back({xs[i].first - xs[i - 1].first, xs[i].second, xs[i - 1].second});
        ve.push_back({ys[i].first - ys[i - 1].first, ys[i].second, ys[i - 1].second});
    }
    sort(ve.begin(), ve.end());
    UnionFind uf(n);
    ll ans = 0;
    for(auto e : ve){
        if(uf.same(e.a, e.b)){ continue; }
        ans += e.len;
        uf.unite(e.a, e.b);
    }
    cout << ans << '\n';
    return 0;
}
