#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define ALL(a) a.begin(), a.end()
#define MOD(a) a %= 1'000'000'007
using ll = long long;
using namespace std;
const int INF32       = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7        = 1'000'000'007;
const int MOD9        = 1'000'000'009;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void print() { std::cout << '\n'; }
void vprint() { std::cout << '\n'; }
template <class H, class... T> void print(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << ' ';
    print(std::forward<T>(args)...);
}
template <class T> void print(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        i == v.size() - 1 ? std::cout << '\n' : std::cout << ' ';
    }
}
template <class T> void print(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << ' ';
        }
    }
}
template <class H, class... T> void vprint(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << '\n';
    vprint(std::forward<T>(args)...);
}
template <class T> void vprint(std::vector<T> &v) {
    for (auto &&i : v) {
        std::cout << i << '\n';
    }
}
template <class T> void mprint(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << "";
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<bool> visited(N);
    vector<vector<int>> g(N);
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    ll ans = 0;

    auto check = [&](vector<bool> &v) {
        for (auto &&i : v) {
            if (i == false)
                return false;
        }
        ans++;
        return true;
    };
    auto dfs = [&](auto f, int now, vector<bool> &vis) -> void {
        if (check(vis))
            return;
        queue<int> nextq;
        REP(i, g[now].size()) {
            int next = g[now][i];
            if (!vis[next])
                nextq.push(next);
        }
        while (!nextq.empty()) {
            int next = nextq.front();
            nextq.pop();
            vis[next] = true;
            f(f, next, vis);
            vis[next] = false;
        }
        return;
    };
    visited[0] = true;
    dfs(dfs, 0, visited);
    print(ans);

    return 0;
}