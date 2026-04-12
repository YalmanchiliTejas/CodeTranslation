#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

struct QuickFind {
    int n, sz;
    vector<int> roots;
    vector<vector<int>> v;
    explicit QuickFind(int n) : n(n), sz(n) {
        v.resize(n);
        for (int i = 0; i < n; ++i) v[i].emplace_back(i);
        roots.resize(n);
        iota(roots.begin(),roots.end(), 0);
    }

    int root(int a){ return roots[a]; }
    int size(int a){ return v[a].size(); }
    int size(){ return sz; }
    bool unite(int a, int b){
        if(same(a, b)) return false;
        sz--;
        a = roots[a], b = roots[b];
        if(size(a) < size(b)) swap(a, b);
        for (auto &&i : v[b]) {
            v[a].emplace_back(i);
            roots[i] = a;
        }
        v[b].clear();
        v[b].shrink_to_fit();
        return true;
    }
    bool same(int a, int b){ return roots[a] == roots[b]; }
    const vector<int>& components(int x){ return v[roots[x]];}
};

template<u32 M = 1000000007>
struct modint{
    u32 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
};
using mint = modint<MOD>;

template<class H>
struct matrix {
    using T = typename H::T;
    vector<vector<T>> A;
    matrix() = default;
    matrix(size_t n, size_t m) : A(n, vector<T>(m)) {}
    explicit matrix(size_t n) : A(n, vector<T> (n)) {};
    size_t height() const { return (A.size()); }
    size_t width() const { return (A[0].size()); }

    const vector<T> &operator [] (int k) const { return A[k]; }
    vector<T> &operator[] (int k) { return A[k]; }

    static matrix I(size_t n){
        matrix mat(n);
        for (int i = 0; i < n; ++i) mat[i][i] = 1;
        return mat;
    }

    matrix &operator+= (const matrix &B){
        size_t h = height(), w = width();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                add((*this)[i][j], B[i][j]);
            }
        }
    }

    matrix &operator-= (const matrix &B){
        size_t h = height(), w = width();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                add((*this)[i][j], -B[i][j]);
            }
        }
    }

    matrix &operator*=(const matrix &B) {
        size_t n = height(), m = B.width(), p = width();
        matrix C(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < p; ++k) {
                    add(C[i][j], mul((*this)[i][k],B[k][j]));
                }
            }
        }
        A.swap(C.A);
        return (*this);
    }

    matrix pow(ll n) const {
        matrix a = (*this), res = I(height());
        while(n > 0){
            if(n & 1) mul(res, a);
            mul(a, a);
            n >>= 1;
        }
        return res;
    }
    matrix operator+(const matrix &B) const {return matrix(*this) += B;}
    matrix operator-(const matrix &B) const {return matrix(*this) -= B;}
    matrix operator*(const matrix &B) const {return matrix(*this) *= B;}

    mint gauss_jordan(){
        mint res = 1;
        int rank = 0;
        for (int c = 0; c < width(); ++c) {
            int k = -1;
            for (int i = rank; i < height(); ++i) {
                if(A[i][c] != H::zero()){
                    k = i;
                    break;
                }
            }
            if(!~k) continue;
            swap(A[k], A[rank]);
            res *= A[rank][c];
            T x = T(1)/A[rank][c];
            for (int j = 0; j < width(); ++j) A[rank][j] *= x;
            for (int i = 0; i < height(); ++i) {
                if(i != rank && A[i][c] != H::zero()){
                    T coeff = A[i][c];
                    for (int j = 0; j < width(); ++j) {
                        A[i][j] -= A[rank][j]*coeff;
                    }
                }
            }
            rank++;
        }
        for (int i = 0; i < min(width(), height()); ++i) {
            res *= A[i][i];
        }
        return res;
    }
};

struct SemiRing {
    using T = mint;
    static inline T mul(T x, T y){ return x * y; }
    static inline void add(T &x, T y){ x += y; }
    static inline T one(){ return 1; }
    static inline T zero(){ return 0; }
};


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> v;
    vector<int> z(m);
    for (int i = 0; i < m; ++i) {
        int s, t, d;
        scanf("%d %d %d", &s, &t, &d);
        s--; t--;
        v.emplace_back(d, s, t);
        z[i] = d;
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    vector<vector<pair<int, int>>> edges(z.size());
    for (int i = 0; i < m; ++i) {
        int d, s, t; tie(d, s, t) = v[i];
        d = lower_bound(z.begin(),z.end(), d) - z.begin();
        edges[d].emplace_back(s, t);
    }
    QuickFind uf(n);
    int val = 0;
    for (int i = 0; i < z.size(); ++i) {
        for (auto &&e : edges[i]) {
            uf.unite(e.first, e.second);
            if(uf.size() == 1){
                val = i;
                i = z.size();
                break;
            }
        }
    }
    printf("%d ", z[val]);
    uf = QuickFind(n);
    for (int i = 0; i < val; ++i) {
        for (auto &&e : edges[i]) {
            uf.unite(e.first, e.second);
        }
    }
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if(!uf.v[i].empty()) roots.emplace_back(i);
    }
    mint ans = 0;
    int C = roots.size();
    for (int i = 1; i < (1 << C)-1; ++i) {
        QuickFind uf2(uf);
        for (int j = 0; j < C; ++j) {
            for (int k = j+1; k < C; ++k) {
                if(((i >> j)& 1) == ((i >> k)& 1)){
                    uf2.unite(roots[j], roots[k]);
                }
            }
        }
        vector<int> l, r;
        for (int j = 0; j < C; ++j) {
            if(i & (1 << j)) {
                if(l.empty()) l = uf2.components(roots[j]);
            }else {
                if(r.empty()) r = uf2.components(roots[j]);
            }
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        mint ret = 1;
        if(l.size() != 1){
            int sz = l.size()-1;
            matrix<SemiRing> A(sz, sz);
            for (int j = 0; j < z.size(); ++j) {
                for (auto &&e : edges[j]) {
                    if(uf2.same(e.first, l[0]) && uf2.same(e.second, l[0])){
                        int x = lower_bound(l.begin(),l.end(), e.first) - l.begin();
                        int y = lower_bound(l.begin(),l.end(), e.second) - l.begin();
                        if(x) A[x-1][x-1] += 1;
                        if(y) A[y-1][y-1] += 1;
                        if(x && y) A[x-1][y-1] -= 1, A[y-1][x-1] -= 1;
                    }
                }
            }
            ret *= A.gauss_jordan();
        }
        if(r.size() != 1){
            int sz = r.size()-1;
            matrix<SemiRing> A(sz, sz);
            for (int j = 0; j < z.size(); ++j) {
                for (auto &&e : edges[j]) {
                    if(uf2.same(e.first, r[0]) && uf2.same(e.second, r[0])){
                        int x = lower_bound(r.begin(),r.end(), e.first) - r.begin();
                        int y = lower_bound(r.begin(),r.end(), e.second) - r.begin();
                        if(x) A[x-1][x-1] += 1;
                        if(y) A[y-1][y-1] += 1;
                        if(x && y) A[x-1][y-1] -= 1, A[y-1][x-1] -= 1;
                    }
                }
            }
            ret *= A.gauss_jordan();
        }
        ans += ret;
    }
    printf("%d\n", ans.val);
    return 0;
}
