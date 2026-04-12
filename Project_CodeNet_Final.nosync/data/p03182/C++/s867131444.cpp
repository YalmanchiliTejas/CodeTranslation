#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf = 1.01e9;
const i64 inf64 = 4.01e18;
const double eps = 1e-9;

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
class segtree {
public:
    int n;
    vector<T> dat, sum;  //区間の和,区間に一様に足された値
    segtree(int size, T x) {
        n = 1;
        while (n < size) n *= 2;
        dat.assign(2 * n - 1, 0);
        sum.assign(2 * n - 1, 0);
        add(0, size, x);
    }
    void add(int a, int b, T x) { add(a, b, x, 0, 0, n); }
    T add(int a, int b, T x, int k, int l, int r) {
        if (b <= l or r <= a) return dat[k];
        if (a <= l and r <= b) {
            sum[k] += x;
            return dat[k] += x;
        }
        int m = (l + r) / 2;
        return dat[k] = max(add(a, b, x, 2 * k + 1, l, m), add(a, b, x, 2 * k + 2, m, r)) + sum[k];
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }
    T query(int a, int b, int k, int l, int r) {
        if (b <= l or r <= a) return -inf64;
        if (a <= l and r <= b) return dat[k];
        int m = (l + r) / 2;
        return max(query(a, b, 2 * k + 1, l, m), query(a, b, 2 * k + 2, m, r)) + sum[k];
    }
};

void solve() {
    //const i64 mod = 1'000'000'007;

    i64 N,M;
    cin >> N >> M;

    vector<vector<pair<i64,i64>>> r_to_la(N);
    rep(i,0,M){
        i64 l,r,a;
        cin >> l >> r >> a;
        --l;
        --r;
        r_to_la[r].emplace_back(make_pair(l,a));
    }

    const i64 maxn=200000;
    segtree<i64> dp(maxn,-inf64);
    rep(r,0,N){
        i64 val=max(i64(0),dp.query(0,r));
        i64 tmp=dp.query(r,r+1);
        dp.add(r,r+1,-tmp);
        dp.add(r,r+1,val);

        for(auto &p:r_to_la[r]){
            i64 l=p.first,a=p.second;
            dp.add(l,r+1,a);
        }
    }

    cout << max(i64(0),dp.query(0,N)) << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
