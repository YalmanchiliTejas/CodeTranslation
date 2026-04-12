#define _GLIBCXX_DEBUG
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
#define invrep(i,n) for(int i=n-1;i>=0;i--)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (int)1000000007
#ifdef int
#define INF LLONG_MAX/10
#else
#define INF INT_MAX/10
#endif
#define DBLINF (DBL_MAX)/10
#define P pair<int,int>

#define vi vector<int>
#define vd vector<double>
#define vvi vector<vector<int>>
#define vvd vector<vector<double>>

#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define all(V) V.begin(),V.end()
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
    if (lhs < rhs) {
        lhs = rhs;
        return 1;
    }
    return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
    if (lhs > rhs) {
        lhs = rhs;
        return 1;
    }
    return 0;
}
using namespace std;
inline int gcd(int a, int b) {
    while (b) {
        int c = a;
        a = b; b = c % b;
    }
    return a;
}
inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
bool isprime(int n) {
    if (n == 1)return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}
int mypow(int a, int b) {
    if (!b)return 1;
    if (b & 1)return mypow(a, b - 1) * a;
    int memo = mypow(a, b >> 1);
    return memo * memo;
}
int modpow(int a, int b, int m = mod) {
    if (!b)return 1;
    if (b & 1)return modpow(a, b - 1, m) * a % m;
    int memo = modpow(a, b / 2, m);
    return memo * memo % m;
}
int read() {
    int x; cin >> x; return x;
}
class modInt {
    int value, modulo;
public:
    modInt() : value(0), modulo(mod) { value = 0; }
    template<typename T>
    modInt(T value = 0, int modulo = mod) : value(value), modulo(modulo) {
        this->value = value % modulo;
    }
    inline operator int()const { return value; }
    inline modInt& operator+=(modInt x) {
        value += x.value;
        if (value >= modulo)value -= modulo;
        return *this;
    }
    inline modInt& operator++() {
        if (value == modulo - 1)value = 0;
        else value++;
        return *this;
    }
    inline modInt& operator-()const {
        return modInt(0) -= *this;
    }
    inline modInt& operator-=(modInt x) {
        value -= x.value;
        if (value < 0)value += modulo;
        return *this;
    }
    inline modInt& operator--() {
        if (value == 0)value = modulo - 1;
        else value--;
        return *this;
    }
    inline modInt& operator*=(modInt x) {
        value = value * x.value % modulo;
        return *this;
    }
    inline modInt& operator/=(modInt x) {
        return operator*=(x.inv());
    }
    inline modInt inv() {
        return modpow(*this, modulo - 2);
    }
    template<typename T> modInt operator+(T x) { return modInt(*this) += x; }
    template<typename T> modInt& operator+=(T x) { return operator+=(modInt(x)); }
    template<typename T> modInt operator-(T x) { return modInt(*this) -= x; }
    template<typename T> modInt& operator-=(T x) { return operator-=(modInt(x)); }
    template<typename T> modInt operator*(T x) { return modInt(*this) *= x; }
    template<typename T> modInt& operator*=(T x) { return operator*=(modInt(x)); }
    template<typename T> modInt operator/(T x) { return modInt(*this) /= x; }
    template<typename T> modInt& operator/=(T x) { return operator/=(modInt(x)); }
};
istream& operator>>(istream& ist, modInt& x) {
    int a;
    ist >> a;
    x = a;
    return ist;
}
modInt modpow(modInt a, int b) {
    if (!b)return modInt(1);
    if (b & 1)return modpow(a, b - 1) * a;
    modInt memo = modpow(a, b / 2);
    return memo * memo;
}
class UnionFind {
protected:
    int* par, * rank, * size;
public:
    UnionFind(unsigned int size) {
        par = new int[size];
        rank = new int[size];
        this->size = new int[size];
        rep(i, size) {
            par[i] = i;
            rank[i] = 0;
            this->size[i] = 1;
        }
    }
    int find(int n) {
        if (par[n] == n)return n;
        return par[n] = find(par[n]);
    }
    void unite(int n, int m) {
        n = find(n);
        m = find(m);
        if (n == m)return;
        if (rank[n] < rank[m]) {
            par[n] = m;
            size[m] += size[n];
        }
        else {
            par[m] = n;
            size[n] += size[m];
            if (rank[n] == rank[m])rank[n]++;
        }
    }
    bool same(int n, int m) {
        return find(n) == find(m);
    }
    int getsize(int n) {
        return size[find(n)];
    }
};
class PerpetualUnionFind :UnionFind {
    P* notparent;
    vector<P>* sizevec;
    int opcount = 0;
public:
    PerpetualUnionFind(unsigned int size) :UnionFind(size) {
        this->sizevec = new vector<P>[size];
        notparent = new P[size];
        rep(i, size) {
            par[i] = i;
            rank[i] = 0;
            sizevec[i].push_back(make_pair(-1, 1));
            notparent[i] = make_pair(INF, i);
        }
    }
    int find(int n, int t = INF) {
        if (opcount <= t) {
            if (par[n] == n)return n;
            return par[n] = find(par[n]);
        }
        if (notparent[n].first <= t)return find(notparent[n].second, t);
        return n;
    }
    void unite(int n, int m) {
        n = find(n);
        m = find(m);
        if (n == m) {
            opcount++;
            return;
        }
        if (rank[n] < rank[m]) {
            par[n] = m;
            notparent[n] = make_pair(opcount, m);
            sizevec[m].push_back(make_pair(opcount, sizevec[m].back().second + sizevec[n].back().second));
        }
        else {
            par[m] = n;
            notparent[m] = make_pair(opcount, n);
            sizevec[n].push_back(make_pair(opcount, sizevec[n].back().second + sizevec[m].back().second));
            if (rank[n] == rank[m])rank[n]++;
        }
        opcount++;
    }
    bool same(int n, int m, int t = INF) {
        return find(n, t) == find(m, t);
    }
    int getsize(int n, int t = INF) {
        n = find(n, t);
        auto ite = lower_bound(sizevec[n].begin(), sizevec[n].end(), make_pair(t, (int)0));
        if (ite == sizevec[n].end())ite--;
        if (t < (*ite).first)ite--;
        return (*ite).second;
    }
};
class RollingHash {
    string s;
    int n, m;
    modInt base;
    vector<modInt> has, power;
public:
    RollingHash(string s, int m, int b) : n(s.size()), m(m), base(b, m) { init(s, m, b); }
    void init(string s, int m, int b) {
        n = s.size();
        has.resize(n);
        power.resize(n);
        base = modInt(b, m);
        this->s = s;
        this->m = m;
        rep(i, n) {
            has[i] = modInt(s[i], m);
            if (i) {
                has[i] += base * has[i - 1];
                power[i] = power[i - 1] * base;
            }
            else power[i] = 1;
        }
    }
    operator int() const {
        return has.back();
    }
    int query(int a, int b) {
        assert(!(a >= b || a < 0 || n < b));
        return has[b - 1] - power[b - a] * (!a ? modInt(0) : has[a - 1]);
    }
    RollingHash& operator+=(string t) {
        s += t;
        has.resize(n + t.size());
        power.resize(n + t.size());
        for (int i = n; i < n + t.size(); i++) {
            has[i] = modInt(t[i] * base, m);
            has[i] += base * has[i - 1];
            power[i] = power[i - 1] * base;
        }
        n += t.size();
        return *this;
    }
};
template<typename T, typename U>
class SegTree {
    int n = 1;
    T* node = NULL;
    U* lazy = NULL;
    bool* lazyflag = NULL;
    T nodee;
    function<T(T, T)> nodef;
    function<U(U, U)> lazyf;
    function<T(T, U, int, int)> updf;
    void eval(int k, int l, int r) {
        if (lazyflag[k]) {
            node[k] = updf(node[k], lazy[k], l, r);
            if (r - l > 1) {
                if (lazyflag[2 * k + 1])lazy[2 * k + 1] = lazyf(lazy[2 * k + 1], lazy[k]);
                else lazy[2 * k + 1] = lazy[k];
                if (lazyflag[2 * k + 2])lazy[2 * k + 2] = lazyf(lazy[2 * k + 2], lazy[k]);
                else lazy[2 * k + 2] = lazy[k];
                lazyflag[2 * k + 1] = lazyflag[2 * k + 2] = true;
            }
            lazyflag[k] = false;
        }
    }
public:
    SegTree(int m, T init, T nodee, function<T(T, T)> nodef, function<U(U, U)> lazyf, function<T(T, U, int, int)> updf) :nodee(nodee), nodef(nodef), lazyf(lazyf), updf(updf) {
        delete[] node;
        delete[] lazy;
        while (n < m)n *= 2;
        node = new T[2 * n], lazy = new U[2 * n], lazyflag = new bool[2 * n];
        for (int i = n - 1; i < 2 * n - 1; i++)node[i] = init;
        for (int i = n - 2; i >= 0; i--)node[i] = nodef(node[2 * i + 1], node[2 * i + 2]);
        rep(i, 2 * n)lazyflag[i] = false;
    }
    SegTree(int m, T nodee, function<T(T, T)> nodef, function<U(U, U)> lazyf, function<T(T, U, int, int)> updf, vector<T> initvec) :nodee(nodee), nodef(nodef), lazyf(lazyf), updf(updf) {
        if (m != initvec.size()) {
            cerr << "Invalid Initialization of SegmentTree" << endl;
            exit(1);
        }
        delete[] node;
        delete[] lazy;
        while (n < m)n *= 2;
        node = new T[2 * n], lazy = new U[2 * n], lazyflag = new bool[2 * n];
        for (int i = n - 1; i < 2 * n - 1; i++) {
            if (i - n + 1 < m)node[i] = initvec[i - n + 1];
            else node[i] = nodee;
        }
        for (int i = n - 2; i >= 0; i--)node[i] = nodef(node[2 * i + 1], node[2 * i + 2]);
        rep(i, 2 * n)lazyflag[i] = false;
    }
    ~SegTree() {
        delete[] node;
        delete[] lazy;
    }
    void update(int a, int b, U x, int k = 0, int l = 0, int r = -1) {
        if (r == -1)r = n;
        eval(k, l, r);
        if (b <= l || r <= a)return;
        if (a <= l && r <= b) {
            lazyflag[k] = true;
            lazy[k] = x;
            eval(k, l, r);
        }
        else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = nodef(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1)r = n;
        eval(k, l, r);
        if (b <= l || r <= a)return nodee;
        if (a <= l && r <= b)return node[k];
        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return nodef(vl, vr);
    }
};
template<typename T>
class RAQRSQ :public SegTree<T, T> {
public:
    RAQRSQ(int size, const T& def = T()) :SegTree<T, T>(size, def, T(), [](T a, T b) {return a + b; }, [](T a, T b) {return a + b; }, [](T a, T b, int l, int r) {return a + (r - l) * b; }) {};
};
template<typename T>
class RAQRMiQ :public SegTree<T, T> {
public:
    RAQRMiQ(int size, const T& def = T()) :SegTree<T, T>(size, def, INF, [](T a, T b) {return min(a, b); }, [](T a, T b) {return a + b; }, [](T a, T b, int l, int r) {return a + b; }) {};
};
template<typename T>
class RAQRMaQ :public SegTree<T, T> {
    using base = SegTree<T, T>;
public:
    RAQRMaQ(int size, const T& def = T()) :base(size, def, -INF, [](T a, T b) {return max(a, b); }, [](T a, T b) {return a + b; }, [](T a, T b, int l, int r) {return a + b; }) {};
};
template<typename T>
class RUQRSQ :public SegTree<T, T> {
    using base = SegTree<T, T>;
public:
    RUQRSQ(int size, const T& def = T()) :base(size, def, T(), [](T a, T b) {return a + b; }, [](T a, T b) {return b; }, [](T a, T b, int l, int r) {return (r - l) * b; }) {};
};
template<typename T>
class RUQRMQ :public SegTree<T, T> {
    using base = SegTree<T, T>;
public:
    RUQRMQ(int size, const T& def = T()) :base(size, def, T(), [](T a, T b) {return min(a, b); }, [](T a, T b) {return b; }, [](T a, T b, int l, int r) {return b; }) {};
};
template<typename T>
class BIT {
    int n;
    T* bit;
public:
    BIT(int n) :n(n) {
        bit = new T[n];
        fill(bit, bit + n, T());
    }
    void add(int a, T x) {
        while (a < n) {
            bit[a] += x;
            a += a & -a;
        }
    }
    T query(int a) {
        int cnt = 0;
        while (a > 0) {
            cnt += bit[a];
            a -= a & -a;
        }
        return cnt;
    }
};
class ConvexHullTrick {
    bool minOrMax, lineMonotone;
    class Line {
    public:
        int a, b;
        bool isquery;
        mutable std::function<const Line * ()> getSuc;
        bool operator<(const Line& x) const {
            if (isquery) {
                const Line* suc = next(this);
                if (suc == nullptr) return true;
                return (suc->a - x.a) * a + suc->b - x.b > 0;
            }
            if (x.isquery) {
                const Line* suc = next(this);
                if (suc == nullptr) return false;
                return (suc->a - a) * x.a + suc->b - b < 0;
            }
            return a < x.a;
        }
    };
    bool isbad(const set<Line>::iterator x) {
        if (x == st.begin() || next(x) == st.end())return false;
        auto pre = prev(x), nex = next(x);
        if (((*x).b - (*pre).b) * ((*nex).a - (*x).a) >= ((*nex).b - (*x).b) * ((*x).a - (*pre).a))return true;
        return false;
    }
    bool isbad(const vector<Line>::iterator x) {
        if (x == vec.begin() || next(x) == vec.end())return false;
        auto pre = prev(x), nex = next(x);
        if (((*x).b - (*pre).b) * ((*nex).a - (*x).a) >= ((*nex).b - (*x).b) * ((*x).a - (*pre).a))return true;
        return false;
    }
    set<Line> st;
    vector<Line> vec;
public:
    ConvexHullTrick(bool minormax = false, bool lineMonotone = false) :minOrMax(minormax), lineMonotone(lineMonotone) {}
    void addLine(int a, int b) {
        if (minOrMax) {
            a = -a; b = -b;
        }
        if (!lineMonotone) {
            auto pos = st.lower_bound({ a,-INF,false });
            if (pos != st.end()) {
                if ((*pos).a == a) {
                    if ((*pos).b <= b)return;
                    st.erase(pos);
                }
            }
            auto ite = st.insert({ a,b,false }).first;
            ite->getSuc = [=] {return next(ite) == st.end() ? nullptr : &*next(ite); };
            if (isbad(ite)) {
                st.erase(ite);
                return;
            }
            while (next(ite) != st.end() && isbad(next(ite)))st.erase(next(ite));
            while (ite != st.begin() && isbad(prev(ite)))st.erase(prev(ite));
        }
        else {
            if (!vec.empty()) {
                if (vec.back().a > a) {
                    cerr << "Line additions are not monotone" << endl;
                    exit(1);
                }
                if (vec.back().a == a) {
                    if (vec.back().b <= b)return;
                    vec.pop_back();
                }
            }
            vec.push_back({ a,b,false });
            auto ite = --vec.end();
            int index = vec.size() - 1;
            ite->getSuc = [this, index] {cout << vec.size() << endl; return index == vec.size() - 1 ? nullptr : &*(vec.begin() + index + 1); };
            while (ite != vec.begin() && isbad(prev(ite))) {
                *prev(ite) = vec.back();
                vec.pop_back();
                ite = --vec.end();
            }
        }
    }
    int query(int x) {
        if (!lineMonotone) {
            auto l = *st.lower_bound(Line{ x, 0,true });
            if (!minOrMax)return l.a * x + l.b;
            else return -l.a * x - l.b;
        }
        else {
            auto l = *lower_bound(vec.begin(), vec.end() - 1, Line({ x,0,true }));
            if (!minOrMax)return l.a * x + l.b;
            else return -l.a * x - l.b;
        }
    }
};
template<typename T>
class Matrix {
    int n;
    T zero, e;
    vector<vector<T>> vec;
    void letmeasure() {
        rep(i, n) {
            rep(j, n) {
                if (i != j)vec[i][j] = zero;
                else vec[i][j] = e;
            }
        }
    }
public:
    Matrix(int n, T zero, T e) :n(n), zero(zero), e(e) {
        vec.resize(n, vector<T>(n));
    }
    Matrix(int n, T zero, T e, vector<int> vec) :n(n), zero(zero), e(e) {
        if (vec.size() != n * n) {
            cerr << "Invalid construct of matrix" << endl;
            exit(1);
        }
        this->vec.resize(n, vector<T>(n));
        rep(i, n) {
            rep(j, n)this->vec[i][j] = vec[i * n + j];
        }
    }
    T& operator[](int a) {
        return vec[a / n][a % n];
    }
    unsigned int size() { return n; }
    Matrix operator*(const Matrix a) {
        if (this->n != a.n) {
            cerr << "Invalid multiply of matrix" << endl;
            exit(1);
        }
        vector<T> memo(n);
        rep(i, n) {
            rep(j, n) {
                rep(k, n) {
                    memo[j] += vec[i][k] * a.vec[k][j];
                }
            }
            vec[i] = memo;
            memo.clear();
            memo.resize(n);
        }
        return *this;
    }
    static Matrix<T> measure(int n, T zero, T e) {
        Matrix<T> res(n, zero, e);
        res.letmeasure();
        return res;
    }
};

class mycomplex {
    double realvalue, imagvalue;
public:
    mycomplex() :realvalue(0), imagvalue(0) {}
    mycomplex(double realvalue, double imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
    mycomplex(double realvalue) : realvalue(realvalue), imagvalue(0) {}
    mycomplex(complex<double> c) :realvalue(c.real()), imagvalue(c.imag()) {}
    mycomplex(const mycomplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
    double real()const { return this->realvalue; }
    double imag()const { return this->imagvalue; }
    double abs() { return hypot(realvalue, imagvalue); }
    mycomplex& operator=(const mycomplex& obj) {
        if (this != &obj) {
            this->realvalue = obj.realvalue;
            this->imagvalue = obj.imagvalue;
        }
        return *this;
    }
    mycomplex& operator=(mycomplex&& obj)noexcept {
        if (this != &obj) {
            this->realvalue = exchange(obj.realvalue, 0);
            this->imagvalue = exchange(obj.imagvalue, 0);
        }
        return *this;
    }
    mycomplex& operator+=(const mycomplex& rhs) {
        this->realvalue += rhs.realvalue;
        this->imagvalue += rhs.imagvalue;
        return *this;
    }
    friend mycomplex operator+(mycomplex lhs, const mycomplex& rhs) {
        lhs += rhs;
        return lhs;
    }
    mycomplex& operator-=(const mycomplex& rhs) {
        this->realvalue -= rhs.realvalue;
        this->imagvalue -= rhs.imagvalue;
        return *this;
    }
    mycomplex& operator-=(const double& rhs) {
        this->realvalue -= rhs;
        return *this;
    }
    friend mycomplex operator-(mycomplex lhs, const mycomplex& rhs) {
        lhs -= rhs;
        return lhs;
    }
    mycomplex& operator*=(const mycomplex& rhs) {
        double pastreal = this->realvalue;
        this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
        this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
        return *this;
    }
    friend mycomplex operator*(mycomplex lhs, const mycomplex& rhs) {
        lhs *= rhs;
        return lhs;
    }
    mycomplex& operator/=(const mycomplex& rhs) {
        *this *= mycomplex(rhs.real(), -rhs.imag());
        double dnm = rhs.real() * rhs.real() - rhs.imag() * rhs.imag();
        this->realvalue /= dnm;
        this->imagvalue /= dnm;
        return *this;
    }
    friend mycomplex operator/(mycomplex lhs, const mycomplex& rhs) {
        lhs /= rhs;
        return lhs;
    }
};
class FastFourierTransform {
private:
    static void dft(vector<mycomplex>& func, int inverse) {
        int sz = func.size();
        if (sz == 1)return;
        vector<mycomplex> veca, vecb;
        rep(i, sz / 2) {
            veca.push_back(func[2 * i]);
            vecb.push_back(func[2 * i + 1]);
        }
        dft(veca, inverse); dft(vecb, inverse);
        mycomplex now = 1, zeta = polar(1.0, inverse * 2.0 * acos(-1) / sz);
        rep(i, sz) {
            func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
            now *= zeta;
        }
    }
public:
    template<typename T>
    static vector<double> multiply(vector<T> f, vector<T> g) {
        vector<mycomplex> nf, ng;
        int sz = 1;
        while (sz < f.size() + g.size())sz *= 2;
        nf.resize(sz); ng.resize(sz);
        rep(i, f.size()) {
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf, 1);
        dft(ng, 1);
        rep(i, sz)nf[i] *= ng[i];
        dft(nf, -1);
        vector<double> res;
        rep(i, sz)res.push_back(nf[i].real() / sz);
        return res;
    }
};
// -*-*-*- Template End -*-*-*-

// -*-*-*- My Template Start -*-*-*-
// Combination (2020.2.22 ABC156D)
modInt modcomb(int n,int k){
    modInt a = 1, b = 1;
    rep(i,k){
        a *= n - i;
        b *= i + 1;
    }
    return a * b.inv();
}
// -*-*-*- My Template End -*-*-*-

signed main() {
    string s;
    cin>>s;

    if(s.at(0) == s.at(1) && s.at(1) == s.at(2)){
        cout<<"No";
    } else {
        cout<<"Yes";
    }
    cout<<endl;
    return 0;
    //cout << ans << endl;
    return 0;
}