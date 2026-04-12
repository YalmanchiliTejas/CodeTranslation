#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
//#define INF (int32)1e9
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

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

class UnionFind{
private:
    ::std::vector<int_fast32_t> par, edge;
    size_t n;

public:
    UnionFind(){}
    UnionFind(size_t n):n(n){
        par.resize(n, -1);
        edge.resize(n, 0);
    }

    uint_fast32_t find(uint_fast32_t x){
        return par[x] < 0 ? x : par[x] = find(par[x]);
    }

    size_t size(uint_fast32_t x){
        return -par[find(x)];
    }

    bool unite(uint_fast32_t x, uint_fast32_t y){
        x = find(x);
        y = find(y);
        edge[x] += 1;
        if(x == y) return false;
        if(size(x) < size(y)) std::swap(x, y);
        par[x] += par[y];
        edge[x] += edge[y];
        par[y] = x;
        return true;
    }

    bool same(uint_fast32_t x, uint_fast32_t y){
        return find(x) == find(y);
    }

    size_t esize(uint_fast32_t x) {
        return edge[find(x)];
    }
};

int main(void) {
    int64 N;
    cin >> N;
    vector<int64> s(N);
    REP(i, N) cin >> s[i];
    int64 res = 0;
    vector<int> visited(N, 0);
    for (int64 i = 1; i <= N-1; i++) {
        int64 sum = 0, pos = 0;
        while (pos < N-i) {
            if (visited[pos] == i || visited[N-1-pos] == i|| pos == N-1-pos) {
                break;
            }
            visited[pos] = visited[N-1-pos] = i;
            sum += s[pos] + s[N-1-pos];
            chmax(res, sum);
            pos += i;
        }

    }
    cout << res << endl;
}
