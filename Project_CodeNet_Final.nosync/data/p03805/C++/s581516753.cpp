#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ull unsigned long long
#define ld long double

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
using VVV = V<V<V<T>>>;

#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rep2(i, 0, n)
#define rep1(i, n) rep1(i, 1, n + 1)

// #define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
// #define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()  //

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(15);
    //    cout << std::setfill('0') << std::setw(2);

    long long N;
    std::cin >> N;
    long long M;
    std::cin >> M;
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i];
        std::cin >> b[i];
        a[i]--;
        b[i]--;
    }
    VV<int> e(N);
    rep(i, M) {
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    V<int> r(N);
    int ans = 0;
    r[0] = 1;
    auto dfs = [&](auto self, int i) -> int {
        bool f = true;
        rep(i, N) {
            if (!r[i]) f = false;
        }
        if (f) {
            return 1;
        }
        int ret = 0;
        for (auto a : e[i]) {
            if (r[a] == 1) continue;
            r[a] = 1;
            ret += self(self, a);
            r[a] = 0;
        }
        return ret;
    };

    cout << dfs(dfs, 0) << endl;
    return 0;
}
