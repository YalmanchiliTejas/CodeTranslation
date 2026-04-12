#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define int long long
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;


struct edge
{
    int to;
    int cost;
    edge(int to, int cost) : to(to), cost(cost) {}
};
typedef vector< vector < edge > > Graph;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<P> cityX, cityY;
    REP(i, N){
        int x, y;
        cin >> x >> y;
        cityX.pb(mp(x, i));
        cityY.pb(mp(y, i));
    }
    sort(All(cityX));
    sort(All(cityY));

    Graph G(N);
    REP(i, N-1) G[cityX[i].second].pb(edge(cityX[i+1].second, cityX[i+1].first - cityX[i].first));
    FOR(i, 1, N) G[cityX[i].second].pb(edge(cityX[i-1].second, cityX[i].first - cityX[i-1].first));

    REP(i, N-1) G[cityY[i].second].pb(edge(cityY[i+1].second, cityY[i+1].first - cityY[i].first));
    FOR(i, 1, N) G[cityY[i].second].pb(edge(cityY[i-1].second, cityY[i].first - cityY[i-1].first));

    vector<int> mincost(N, INF);
    vector<bool> used(N, false);
    priority_queue<P, vector<P>, greater<P>> Q; // cost, number
    int res = 0;

    Q.emplace(0, 0);
    while(!Q.empty()){
        P v = Q.top(); Q.pop();
        if(used[v.second]) continue;
        used[v.second] = true;
        res += v.first;
        for(auto &e : G[v.second]) {
            Q.emplace(e.cost, e.to);
        }
    }

    cout << res << "\n";
    return 0;
}