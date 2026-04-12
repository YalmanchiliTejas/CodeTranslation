#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fwr(x) { cout << x << '\n'; }

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int inf = 1e9 + 7;
const ll linf = 1ll * inf * inf;
const int N = 1000000 + 1;
const int M = 5000;
const int multipleTest = 0;
const double pi = acos(-1);

vii adj[N];
vector<ll> L, D;
vector<int> L_cnt, D_cnt;
int n, m;
int S, T;


void dijkstra(int root, vector<ll>& dist, vector<int>& cnt) {
    dist.resize(n + 1); cnt.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        dist[i] = linf;
        cnt[i] = 0;
    }
    dist[root] = 0;
    cnt[root] = 1;
    
    priority_queue<pair<ll, int>> heap;
    heap.push(make_pair(0, root));
    
    while (!heap.empty()) {
        int u = heap.top().second;
        ll cur = -heap.top().first;
        heap.pop();
        if (dist[u] != cur) continue;

        for (ii x : adj[u]) {
            int v = x.first;
            int cost = x.second;
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                cnt[v] = cnt[u];
                heap.push(make_pair(-dist[v], v));
            } else {
                if (dist[v] == dist[u] + cost) {
                    cnt[v] += cnt[u];
                    if (cnt[v] >= inf) cnt[v] -= inf;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    cin >> S >> T;
    rep(i, 0, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    
    dijkstra(S, L, L_cnt);
    dijkstra(T, D, D_cnt);
    
    ll res = L_cnt[T];
    res = res * res;
    res %= inf;
    
    ll maxLength = L[T];
    
    for (int i = 1; i <= n; ++i) {
        if (L[i] + D[i] == maxLength && L[i] == D[i]) {
            ll tmp = (ll)L_cnt[i] * D_cnt[i] % inf;
            res = (res - tmp * tmp) % inf;
            if (res < 0) res += inf;
        }
        for (ii x : adj[i]) {
            int j = x.first;
            int c = x.second;
            
            if (L[i] + c + D[j] == maxLength && L[i] * 2 < maxLength && D[j] * 2 < maxLength) {
                ll tmp = (ll)L_cnt[i] * D_cnt[j] % inf;
                res = (res - tmp * tmp) % inf;
                if (res < 0) res += inf;
            }
        }
    }
    
    
    cout << res;
}

int main() {
#ifdef _LOCAL_
    freopen("inp.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
#endif
    
    int Test = 1;
    if (multipleTest)
        cin >> Test;
    
    for(int i = 0; i < Test; ++i) {
        //        printf("Case #%d: ", i + 1);
        solve();
    }
#ifdef _LOCAL_
    cout<< "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}
