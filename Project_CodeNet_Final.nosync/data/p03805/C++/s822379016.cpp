#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int bitCount(long bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int n;
bool visited[8];
bool p[8][8];

int dfs(int v) {
    bool all = true;
    rep (i, n) {
        if (visited[i] == false) all = false;
    }
    if (all) return 1;
    int res = 0;
    rep (i, n) {
        if (p[v][i] == false) continue;
        if (visited[i]) continue;
        visited[i] = true;
        res += dfs(i);
        visited[i] = false;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    rep (i, n) {
        rep (j, n) {
            p[i][j] = false;
        }
        visited[i] = false;
    }
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        p[a][b] = true, p[b][a] = true;
    }
    visited[0] = true;
    cout << dfs(0) << endl;
    
    return 0;
}

