#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <list>

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<const int, int> pii;

const int MAXN = 1e5 + 1;
const int inf = 1e9 + 5;
const long double eps = 1e-8;

vector<int> g[MAXN];
set<int> s[MAXN];

void removeNode(map<int, int> &q, int v) {
    for (int i = 0; i < g[v].size(); i++) {
        if (q.find(g[v][i]) != q.end()) {
            int c = q[g[v][i]];
            s[c].erase(g[v][i]);
            s[c - 1].insert(g[v][i]);
            q[g[v][i]]--;
        }
    }
    s[q[v]].erase(v);
    q.erase(v);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    map<int, int> q;

    for (int i = 0; i < n; i++) {
        q[i] = g[i].size();
        s[g[i].size()].insert(i);
    }

    while (!q.empty()) {
        if (!s[0].empty()) {
            cout << "First";
            return 0;
        }
        int v;
        if (!s[1].empty()) {
            v = *(s[1].begin());
        } else
            return 13;

        for (int i = 0; i < g[v].size(); i++) {
            if (q.find(g[v][i]) != q.end()) {
                removeNode(q, g[v][i]);
            }
        }
        s[q[v]].erase(v);
        q.erase(v);
    }

    cout << "Second";

    return 0;
}