#include <algorithm>
#include <climits>
#include <complex>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

// using
using namespace std;

// typedef
typedef long long ll;

// define
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQ(c) unique(ALL(c))
#define FOR(i, a, b, c) for (int i = (int)(a); i < (int)(b); i += (int)(c))
#define REP(i, n) FOR(i, 0, n, 1)
#define RFOR(i, a, b, c) for (int i = (int)(a); i >= (int)(b); i -= (int)(c))
#define RREP(i, n) RFOR(i, n, 0, 1)

// functions
template <class T> T ceil(T a, T b) {
    return (a + b - 1) / b;
}
template <class T> T round(T a, T b) {
    return (a + b / 2) / b;
}
template <class T> T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}
template <class T> bool amax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> bool amin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

int N, M;
vector<vector<bool>> G(8, vector<bool>(8, false));

int dfs(int v, vector<bool> visited) {
    bool all_visited = true;
    REP(i, N) {
        if (!visited[i]) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) {
        return 1;
    }

    int res = 0;
    REP(i, N) {
        if (!G[v][i]) {
            continue;
        } else if (visited[i]) {
            continue;
        }

        visited[i] = true;
        res += dfs(i, visited);
        visited[i] = false;
    }
    return res;
}

// main
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        G[a - 1][b - 1] = true;
        G[b - 1][a - 1] = true;
    }

    vector<bool> visited(N, false);
    visited[0] = true;
    cout << dfs(0, visited) << endl;
    return 0;
}
