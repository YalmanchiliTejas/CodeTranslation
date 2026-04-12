#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

const int N_MAX = 8;
vector<vector<int>> graph;
int n, m;


void dfs(int v, vector<bool> &used, int &res) {
    bool complete = true;

    rep(i, n) {
        if (!used[i] && i != v) complete = false;
    }

    if (complete) {
        res++;
        return;
    }

    used[v] = true;
    for (auto u: graph[v]) {
        if (used[u]) continue;
        dfs(u, used, res);
    }
    used[v] = false;
}


int main(){
    cin >> n >> m;
    graph.assign(n, vector<int>());
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> used(n, false);

    int res = 0;
    dfs(0, used, res);
    cout << res << endl;
}