// http://arc076.contest.atcoder.jp/submissions/1375863 の改造
// クラスカル法からプリム法に変更

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii; // (cost, to)

const int MAX_N = 100000;
int n;
vector<pii> G[MAX_N];

// http://algoogle.hadrori.jp/algorithm/prim.html
ll prim() {
    priority_queue<pii, vector<pii>, greater<pii> > que;
    vector<bool> used(n, false);
    que.push(pii(0,0));
    ll ret = 0;
    while(!que.empty()) {
        ll cost = que.top().first;
        int v = que.top().second;
        que.pop();
        if(used[v]) {
            continue;
        }
        used[v] = true;
        ret += cost;
        for (auto& e : G[v]) {
            que.push(pii(e.first, e.second));
        }
    }
    return ret;
}

void add_edge(int i, int j, int cost) {
    G[i].push_back(pii(cost, j));
    G[j].push_back(pii(cost, i));
}

int main() {
    cin >> n;
    vector<pair<ll, ll>> ps(n);
    for (auto& p : ps)
        cin >> p.first >> p.second;
 
    // xord[i] x座標がi番目に小さいpointのid
    // yord[i] y座標がi番目に小さいpointのid
    vector<int> xord(n), yord(n);
    for (int i = 0; i < n; i++) {
        xord[i] = i;
        yord[i] = i;
    }
    sort(xord.begin(), xord.end(), [&](int a, int b) { return ps[a].first < ps[b].first; });
    sort(yord.begin(), yord.end(), [&](int a, int b) { return ps[a].second < ps[b].second; });
 
    for (int i = 1; i < n; i++) {
        add_edge(xord[i], xord[i - 1], ps[xord[i]].first  - ps[xord[i - 1]].first);
        add_edge(yord[i], yord[i - 1], ps[yord[i]].second - ps[yord[i - 1]].second);
    }
    cout << prim() << endl;
    return 0;
}