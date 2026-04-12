#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> cnt(n, 0);
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
        ++cnt[a];
        ++cnt[b];
    }
    
    queue<int> q;
    REP(i, n) {
        if (cnt[i] == 1) q.push(i);
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (!cnt[v]) continue;
            cnt[v] = 0;
            int k = 0;
            for (int v_ : G[v]) {
                if (!cnt[v_]) continue;
                --cnt[v_];
                if (cnt[v_] == 1) q.push(v_);
                if (!cnt[v_]) ++k;
            }
            if (k >= 2) {
                cout << "First\n";
                return 0;
            }
        }
        cnt[u] = 0;
    }
    
    cout << "Second\n";
    return 0;
}
