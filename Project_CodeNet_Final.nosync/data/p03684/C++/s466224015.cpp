#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

int main(){
    int N;  cin >> N;
    vector<tuple<int,int,int>> Pos(N);
    for(int i=0; i<N; i++){
        int x, y;  cin >> x >> y;
        Pos[i] = make_tuple(i, x, y);
    }
    sort(Pos.begin(), Pos.end(), [](const tuple<int,int,int> &a, const tuple<int,int,int> &b){
        return get<1>(a) < get<1>(b);
    });
    vector<vector<pair<int,ll>>> G;
    G = vector<vector<pair<int,ll>>>(N, vector<pair<int,ll>>());
    for(int i=0; i<N-1; i++){
        int n1 = get<0>(Pos[i]), n2 = get<0>(Pos[i+1]);
        ll dx = abs(get<1>(Pos[i]) - get<1>(Pos[i+1]));
        ll dy = abs(get<2>(Pos[i]) - get<2>(Pos[i+1]));
        G[n1].push_back(make_pair(n2,min(dx, dy)));
        G[n2].push_back(make_pair(n1,min(dx, dy)));
    }
    sort(Pos.begin(), Pos.end(), [](const tuple<int,int,int> &a, const tuple<int,int,int> &b){
        return get<2>(a) < get<2>(b);
    });
    for(int i=0; i<N-1; i++){
        int n1 = get<0>(Pos[i]), n2 = get<0>(Pos[i+1]);
        ll dx = abs(get<1>(Pos[i]) - get<1>(Pos[i+1]));
        ll dy = abs(get<2>(Pos[i]) - get<2>(Pos[i+1]));
        G[n1].push_back(make_pair(n2,min(dx, dy)));
        G[n2].push_back(make_pair(n1,min(dx, dy)));
    }

    ll ans = 0;
    vector<bool> used(N,false);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
    que.push(make_pair(0,0));
    while(!que.empty()){
        pair<ll,int> p = que.top();
        que.pop();
        ll cost = p.first;
        int v = p.second;
        if(used[v]) continue;
        used[v] = true;
        ans += cost;
        for(int i=0; i<G[v].size(); i++){
            que.push(make_pair(G[v][i].second, G[v][i].first));
        }
    }
    cout << ans << endl;
}
