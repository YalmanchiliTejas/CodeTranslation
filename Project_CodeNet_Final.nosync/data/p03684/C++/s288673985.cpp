#include <bits/stdc++.h>
#define MAX_V 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> graph[MAX_V];
bool used[MAX_V] = {false,};

ll prim(){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(pii(0,0));
    ll cost_sum = 0;
    while(!q.empty()){
        int cost = q.top().first;
        int v = q.top().second;
        q.pop();
        if(used[v]){continue;}
        used[v] = true;
        cost_sum += cost;
        for(auto edge : graph[v]){
            if(used[edge.second]){continue;}
            q.push(pii(edge.first,edge.second));
        }
    }
    return cost_sum;
}

int main(){
    int n;
    cin >> n;
    vector<pii> town_x(n),town_y(n);
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        town_x[i] = {x,i};
        town_y[i] = {y,i};
    }
    sort(town_x.begin(),town_x.end());
    sort(town_y.begin(),town_y.end());

    int src, dst, cost;
    for(int i = 0; i < n-1; i++){
        src = town_x[i].second;
        dst = town_x[i+1].second;
        cost = town_x[i+1].first-town_x[i].first;
        graph[src].push_back({cost,dst});
        graph[dst].push_back({cost,src});
        src = town_y[i].second;
        dst = town_y[i+1].second;
        cost = town_y[i+1].first-town_y[i].first;
        graph[src].push_back({cost,dst});
        graph[dst].push_back({cost,src});
    }
    ll ans = prim();
    cout << ans << endl;

    return 0;

}
