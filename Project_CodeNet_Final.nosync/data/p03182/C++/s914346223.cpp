#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

template<class T>
class StarrySkyTree {
    private:
        int N;
        const T MIN;
        const T ZERO;
        std::vector<T> dat, lazy;
    public:
        StarrySkyTree(int n) : MIN(std::numeric_limits<T>::min()), ZERO(static_cast<T>(0)) {
            N = 1;
            while (N < n) N *= 2;
            dat.assign(2*N, MIN);
            lazy.assign(2*N, ZERO);
        }
        // a is 0-indexed
        void set(int a, const T v) { dat[a+N] = v; }
        void build() { for (int i=N-1; i>0; --i) dat[i] = std::max(dat[2*i], dat[2*i+1]); }
        void eval(int k, int l, int r) {
            if (lazy[k] == ZERO) return;

            dat[k] += lazy[k];
            if (r - l > 1) {
                lazy[2*k] += lazy[k];
                lazy[2*k+1] += lazy[k];
            }
            lazy[k] = ZERO;
        }
        // add v to [a, b)
        // a and b are 0-indexed
        void add(int a, int b, const T v) { return add (a, b, v, 1, 0, N); }
        void add(int a, int b, const T v, int k, int l, int r) {
            eval(k, l, r);

            if (b <= l || r <= a) return;
            if (a <= l && r <= b) {
                lazy[k] += v;
                eval(k, l, r);
            } else {
                add(a, b, v, 2*k, l, (l+r)/2);
                add(a, b, v, 2*k+1, (l+r)/2, r);
                dat[k] = std::max(dat[2*k], dat[2*k+1]);
            }
        }
        // get max of [a, b)
        // a and b are 0-indexed
        T get(int a, int b) { return get(a, b, 1, 0, N); }
        T get(int a, int b, int k, int l, int r) {
            eval(k, l, r);

            if (b <= l || r <= a) return MIN;
            if (a <= l && r <= b) return dat[k];
            T vleft = get(a, b, 2*k, l, (l+r)/2);
            T vright = get(a, b, 2*k+1, (l+r)/2, r);
            return std::max(vleft, vright);
        }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> ls(N+1);
    for (int i=0; i<M; ++i) {
        int l, r, a;
        cin >> l >> r >> a;
        ls[r].emplace_back(l, a);
    }

    StarrySkyTree<ll> dp(N+1);
    for (int i=0; i<N+1; ++i) dp.set(i, 0);
    dp.build();
    for (int i=1; i<N+1; ++i) {
        dp.add(i, i+1, dp.get(0, i));
        for (auto p : ls[i]) dp.add(p.first, i+1, p.second);
    }
    cout << dp.get(0, N+1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
