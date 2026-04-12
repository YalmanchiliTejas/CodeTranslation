#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair< int, int > iP;
typedef pair< iP, int > iiP;

vector< iP > pp;
int prim(vector< vector< int > > &g) {
    int ret = 0;
    int s = g.size();
    priority_queue< iP, vector< iP >, greater< iP > > q;
    vector< int > v(s, 0);
    q.push(iP(0, 0));
    while(!q.empty()) {
        iP p = q.top(); q.pop();
        if(v[p.second]++) continue;
        ret += p.first;
        int now = p.second;
        for(int i = 0; i < g[now].size(); i++) {
            q.push(iP(min(abs(pp[now].first - pp[g[now][i]].first), abs(pp[now].second - pp[g[now][i]].second)), g[now][i]));
        }
    }

    return ret;
}

int main() {

    int n;
    vector< iiP > g1, g2;
    vector< vector< int > > g0;

    cin >> n;
    g0.resize(n + 1);
    pp.resize(n);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pp[i] = iP(x, y);
        g1.push_back(iiP(iP(x, y), i));
        g2.push_back(iiP(iP(y, x), i));
    }
    sort(g1.begin(), g1.end());
    sort(g2.begin(), g2.end());
    for(int i = 0; i < n; i++) {
        int pre = (i - 1 + n) % n;
        int nxt = (i + 1) % n;
        g0[g1[i].second].push_back(g1[pre].second), g0[g1[i].second].push_back(g1[nxt].second);
        g0[g2[i].second].push_back(g2[pre].second), g0[g2[i].second].push_back(g2[nxt].second);
    }

    cout << prim(g0) << endl;
}
