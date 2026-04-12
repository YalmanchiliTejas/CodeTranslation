#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAX_N = 300000;
int par[MAX_N];
int t_rank[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        t_rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;

    if (t_rank[x] < t_rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (t_rank[x] == t_rank[y]) t_rank[x]++;
    }
    return true;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

ll N;
ll ans = 0;

void solve() {
    cin >> N;
    pair<ll,ll> X[N];// x, id  
    pair<ll,ll> Y[N];
    rep(i,N) {
        ll x, y;
        cin >> x >> y;
        X[i] = pair<ll,ll>(x,i);
        Y[i] = pair<ll,ll>(y,i);
    }
    sort(X,X+N);
    sort(Y,Y+N);
    vector<pair<ll, pair<ll,ll>>> E; // length, from, to
    REP(i,1,N) {
        pair<ll, pair<ll,ll>> p1(X[i].first-X[i-1].first, pair<ll,ll>(X[i].second, X[i-1].second));
        pair<ll, pair<ll,ll>> p2(Y[i].first-Y[i-1].first, pair<ll,ll>(Y[i].second, Y[i-1].second));
        E.push_back(p1);
        E.push_back(p2);
    }
    sort(E.begin(), E.end());
    init(N);
    rep(i,E.size()) {
        ll cost = E[i].first;
        ll from = E[i].second.first;
        ll to = E[i].second.second;
        if (!same(from, to)) {
            unite(from, to);
            ans += cost;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    solve();
    return 0;
}
