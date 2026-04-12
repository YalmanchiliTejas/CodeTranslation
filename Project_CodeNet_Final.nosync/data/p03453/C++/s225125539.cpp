#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

struct edge{
    int to;
    ll cost;
};

//V:=頂点数、E:=辺数
const int MAX_V = 1e5;
vector<edge> es[MAX_V];
ll d[MAX_V], d2[MAX_V];

//グラフに負の辺がない場合に、O(E*log(V))でsから全ての点への最短距離をそれぞれ求める
void dijkstra(int s, ll *d){
    priority_queue<pli, vector<pli>, greater<pli> > que;
    fill(d, d+MAX_V, INF);
    d[s] = 0;
    que.push(pli(0, s));
    while(!que.empty()){
        pli p = que.top();
        que.pop();
        int v = p.second;
        //d[v]が確定している
        if(d[v] < p.first) continue;
        for(auto &e: es[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(pli(d[e.to], e.to));
            }
        }
    }
}

//num[i]:=sからtへの最短路の途中でiによる場合の数
ll num[MAX_V], num2[MAX_V];
priority_queue<pli> q;
bool used[MAX_V];

void dfs(int now, ll *d, ll *num){
    used[now] = true;
    for(auto &e: es[now]){
        if(d[now] == d[e.to]+e.cost){
            num[e.to] += num[now];
            num[e.to] %= MOD;
            q.push(pli(d[e.to], e.to));
        }
    }
}

void calc(int s, int t, ll *d, ll* num){
    fill(num, num+MAX_V, 0);
    fill(used, used+MAX_V, false);
    dijkstra(t, d);
    num[s] = 1;
    q.push(pli(d[s], s));
    while(!q.empty()){
        pli p = q.top();
        q.pop();
        if(!used[p.second]) dfs(p.second, d, num);
    }
}

int main(){
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    s--, t--;
    rep(i, M){
        int u, v;
        ll r;
        cin >> u >> v >> r;
        u--, v--;
        edge e1 = {v, r}, e2 = {u, r};
        es[u].pb(e1), es[v].pb(e2);
    }
    calc(s, t, d, num);
    calc(t, s, d2, num2);
    ll D = d[s];
    vector<pii> check;
    rep(i, N){
        if(d[i]*2 == D && d2[i]*2 == D) check.pb(pii(i, i));
    }
    //d[i]:=tからiの最短距離、d2[i]:=sからiの最短距離
    rep(i, N){
        for(auto &e: es[i]){
            if(d2[i]+e.cost+d[e.to] == D){
                if(d2[i]*2 < D && d[e.to]*2 < D){
                    check.pb(pii(i, e.to));
                }
            }
        }
    }
    ll ans = num[t]*num2[s]%MOD;
    for(auto &e: check){
        //cout << e.first << ' ' << e.second << endl;
        ll tmp = num[e.first]*num2[e.second]%MOD;
        tmp *= tmp, tmp %= MOD;
        ans += MOD-tmp, ans %= MOD;
    }
    cout << ans << endl;
}