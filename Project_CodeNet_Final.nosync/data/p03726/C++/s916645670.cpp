#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

int sz[100001];

int dfs(int v, int p, vector<vector<int>> &G) {
    if (sz[v]) return sz[v];
    int ret = 1;
    for(int i = 0; i < G[v].size(); i++) {
        if (G[v][i] == p) continue;
        ret += dfs(G[v][i], v, G);
    }
    return sz[v] = ret;
}

int hasNmata(int v, int p, vector<vector<int>> &G) {
    if (sz[v] == 1) return 0;
    int ret = 0;
    int cnt = 0;
    for(int i = 0; i < G[v].size(); i++) {
        if (G[v][i] == p) continue;
        if (sz[G[v][i]] % 2 == 1) cnt++;
    }
    ret |= cnt >= 2;

    for(int i = 0; i < G[v].size(); i++) {
        if (G[v][i] == p) continue;
        ret |= hasNmata(G[v][i], v, G);
    }
    return ret;
}

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1, G);
    int flag = hasNmata(0, -1, G);
    if (flag || N % 2 == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}