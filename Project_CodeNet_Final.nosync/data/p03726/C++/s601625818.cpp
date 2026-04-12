#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

vector<int> g[N];

int used[N], k[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        ++k[a];
        ++k[b];
    }
    if (n == 2) {
        cout << "Second";
        return 0;
    }
    queue<int> q, w;
    for (int i = 1; i <= n; ++i) {
        if (k[i] == 1) {
            used[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        bool f = false;
        for (int u : g[v]) {
            if (!used[u]) {
                used[u] = 1;
                f = true;
                for (int i : g[u]) {
                    if (--k[i] == 1 && !used[i]) {
                        w.push(i);
                    }
                }
                break;
            }
        }
        if (!f) {
            cout << "First";
            return 0;
        }
        if (q.empty()) {
            while (!w.empty()) {
                if (!used[w.front()]) {
                    q.push(w.front());
                }
                w.pop();
            }
        }
    }
    cout << "Second";
    return 0;
}