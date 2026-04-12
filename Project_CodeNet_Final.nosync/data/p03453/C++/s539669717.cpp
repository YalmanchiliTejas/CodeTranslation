#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cout << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

struct edge{
    int to; ll cost;
};

void solve() {
	int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    --s; --t;
    vector<edge> G[100100];
    rep(i, m) {
        int u, v; ll d; cin >> u >> v >> d;
        --u; --v;
        G[u].pb(edge{v, d});
        G[v].pb(edge{u, d});
    }
    
    priority_queue<P, vector<P>, greater<P>> que;
    vector<ll> dist1(n, INF), dist2(n, INF);
    vector<ll> num1(n, 0), num2(n, 0);

    dist1[s] = 0; num1[s] = 1LL;
    que.push(make_pair(0, s));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.sc;
        if(dist1[v] < p.fr) continue;
        for(auto u: G[v]) {
            if(dist1[u.to] > dist1[v] + u.cost) {
                dist1[u.to] = dist1[v] + u.cost;
                num1[u.to] = num1[v];
                que.push(P(dist1[u.to], u.to));
            } else if(dist1[u.to] == dist1[v] + u.cost) {
                num1[u.to] += num1[v];
                num1[u.to] %= mod;
            }
        }
    }

    dist2[t] = 0; num2[t] = 1LL;
    que.push(make_pair(0, t));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.sc;
        if(dist2[v] < p.fr) continue;
        for(auto u: G[v]) {
            if(dist2[u.to] > dist2[v] + u.cost) {
                dist2[u.to] = dist2[v] + u.cost;
                num2[u.to] = num2[v];
                que.push(P(dist2[u.to], u.to));
            } else if(dist2[u.to] == dist2[v] + u.cost) {
                num2[u.to] += num2[v];
                num2[u.to] %= mod;
            }
        }
    }

    ll d = dist1[t];
    ll res = (num1[t] * num2[s]) % mod;

    //頂点x上で出会うもの
    rep(x, n) {
        if(dist1[x] + dist2[x] == d && dist1[x] == dist2[x]) {
            ll sub = (num1[x] * num2[x]) % mod;
            res -= ((sub * sub) % mod);
            (res += mod) %= mod;
        }
    }

    //辺(x, y)上で出会うもの
    //出会わないといけない->きちんとシミュレーションして確認すべし（きちんと衝突する場合を考えてるのか）（この条件できちんと全ての衝突する場合を言えているのか、必要十分な条件なのか）
    //きちんと必要十分な条件なのかを確認する！！！！！！！！
    rep(x, n) {
        for(auto p: G[x]) {
            int y = p.to; ll cost = p.cost;
            if(dist1[x] + cost + dist2[y] != d) continue;
            if(dist1[x] == dist2[x] || dist1[y] == dist2[y]) continue; //重複を防ぐ
            if(dist1[y] > dist2[y] && dist1[x] < dist2[x]) {
                ll sub = ((num1[x] * num2[y]) % mod);
                res -= ((sub * sub) % mod);
                (res += mod) %= mod;
            }
        }
    }

    cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}