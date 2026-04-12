// THANK YOU MR SOLVING!!!!!!!!

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using std::sort;
using std::reverse;

using ll = long long;

#define forn(i, n) for (ll i = 0; i < (ll) n; ++i)
#define sz(a) static_cast<int>(a.size())
#define push_back emplace_back
#define endl '\n'

class solver {
private:
    double TIME;

    static const ll INF = static_cast<ll>(1e9) + 7;
    static const int MAXN = static_cast<ll>(1e6) + 17;
    const int MAGIC = 62;

    int n;
    vector< vector<int> > g, dp;

public:
    static bool FLAG;

    solver() {
        TIME = static_cast<double>(clock()) / CLOCKS_PER_SEC;
    }

    bool read() {
        if (!(cin >> n))
            return false;

        g.resize(n);

        forn (i, n - 1) {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }

        return true;
    }

    void dfs(int v, int p) {
        for (auto to : g[v])
            if (to != p)
                dfs(to, v);

        int sum = 0, mn = INF;

        for (auto to : g[v])
            if (to != p) {
                sum += max(dp[to][0], dp[to][1]);
                mn = min(mn, max(dp[to][0], dp[to][1]) - dp[to][0]);
            }

        dp[v][0] = sum;

        if (sz(g[v]) - (v != p) > 0)
            dp[v][1] = 1 + sum - mn;
    }

    void solve() {
        dp.resize(n, vector<int>(2, 0));
        dfs(0, 0);
        int mt = max(dp[0][0], dp[0][1]);

        if (mt * 2 == n)
            cout << "Second\n";
        else
            cout << "First\n";
    }

    ~solver() {
#ifdef SEREZHKA
        if (FLAG)
            cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC - TIME << endl;
#endif
    }
};

bool solver::FLAG = true;

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(5);

#ifdef SEREZHKA
    freopen("file.in", "r", stdin);
    std::mt19937 rand('S' + 'E' + 'R' + 'E' + 'Z' + 'H' + 'K' + 'A');
#else
    std::mt19937 rand(time(NULL));
#endif

    while (solver::FLAG) {
        solver solution;

        if (!solution.read())
            solver::FLAG = false;
        else
            solution.solve();
    }

    return 0;
}
