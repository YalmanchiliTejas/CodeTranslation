#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

struct path{
    int to;
    ll cost;
};
int main() {
    //cout.precision(10);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<path> pathes[100020];
    for(int i = 1; i <= m; i++){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        d = d * 2;
        pathes[u].push_back({v, d});
        pathes[v].push_back({u, d});
    }
    ll field[100020];
    ll field2[100020];
    for(int i = 0; i <= n; i++){
        field[i] = 1e17;
        field2[i] = 1e17;
    }
    priority_queue<pair<ll, int> , vector<pair<ll, int> >, greater<pair<ll, int> > > que;
    priority_queue<pair<ll, int> , vector<pair<ll, int> >, greater<pair<ll, int> > > que2;
    que2.push({0, t});
    que.push({0, s});
    while(!que.empty()){
        int now = que.top().second;
        ll NewCost = que.top().first;
        que.pop();
        if(field[now] < 1e17){
            continue;
        }
        field[now] = NewCost;
        for(int i = 0; i < pathes[now].size(); i++){
            path out = pathes[now][i];
            que.push({out.cost + NewCost, out.to});
        }
    }
    while(!que2.empty()){
        int now = que2.top().second;
        ll NewCost = que2.top().first;
        que2.pop();
        if(field2[now] < 1e17){
            continue;
        }
        field2[now] = NewCost;
        for(int i = 0; i < pathes[now].size(); i++){
            path out = pathes[now][i];
            que2.push({out.cost + NewCost, out.to});
        }
    }
    ll target = field[t];
    //cout << "target is " << target << endl;
    for(int i = 1; i <= n; i++){
        if((field[i] + field2[i]) != target){
            field[i] = 1e17;
            field2[i] = 1e17;
        } else {
            //cout << "safe " << i << " " << field[i] << " " << field2[i] << endl;
        }
    }
    bool used[100002];
    bool used2[100002];
    target = target / 2;
    ll ways[100020];
    ll ways2[100020];
    for(int i = 0; i <= n; i++){
        ways[i] = 0;
        ways2[i] = 0;
        used2[i] = false;
        used[i] = false;
    }
    ways2[t] = 1;
    ways[s] = 1;
    vector<pair<i_i, ll> >ans;
    vector<pair<i_i, ll> >ans2;
    while(!que2.empty()){
        que2.pop();
    }
    while(!que.empty()){
        que.pop();
    }
    que.push({0, s});
    que2.push({0, t});
    while(!que.empty()){
        int now = que.top().second;
        ll NewCost = que.top().first;
        //cout << NewCost << endl;
        que.pop();
        if(used[now]){
            continue;
        }
        used[now] = true;
        //cout << "field1 " << now << " " << field[now] << " " << ways[now] << endl;
        if(NewCost == target){
            ans.push_back({{now, now}, ways[now]});
            //continue;
        }
        for(int i = 0; i < pathes[now].size(); i++){
            path out = pathes[now][i];
            if(NewCost + out.cost != field[out.to]) continue;
            if((NewCost + out.cost > target) && (NewCost < target)){
                //cout << now << " " << out.to << endl;
                ans.push_back({{now, out.to}, ways[now]});
                //continue;
            }
            ways[out.to] += ways[now];
            ways[out.to] = ways[out.to] % mod;
            que.push({out.cost + NewCost, out.to});
        }
    }
    while(!que2.empty()){
        int now = que2.top().second;
        ll NewCost = que2.top().first;
        //cout << NewCost << endl;
        que2.pop();
        if(used2[now]){
            continue;
        }
        used2[now] = true;
        //cout << "field2 " << now << " " << field2[now] << " " << ways2[now] << endl;
        if(NewCost == target){
            ans2.push_back({{now, now}, ways2[now]});
            continue;
        }
        for(int i = 0; i < pathes[now].size(); i++){
            path out = pathes[now][i];
            if((NewCost + out.cost) != field2[out.to]) continue;
            if((NewCost + out.cost) > target){
                //cout << now << " " << out.to << endl;
                ans2.push_back({{out.to, now}, ways2[now]});
                continue;
            }
            ways2[out.to] += ways2[now];
            ways2[out.to] = ways2[out.to] % mod;
            que2.push({out.cost + NewCost, out.to});
        }
    }
    sort(ans.begin(), ans.end());
    sort(ans2.begin(), ans2.end());
    ll sum1 = 0, sum2 = 0;
    //cout << "ans1" << endl;
    for(int i = 0; i < ans.size(); i++){
        sum1 = (sum1 + ans[i].second) % mod;
        //if(ans[i].first.first == ans[i].first.second){
        //    cout << ans[i].first.first << " " << ans[i].second;
        //}
        //cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
    }
    //cout << "ans2" << endl;
    for(int i = 0; i < ans2.size(); i++){
        sum2 = (sum2 + ans2[i].second) % mod;
        //if(ans2[i].first.first == ans2[i].first.second){
            //cout << ans2[i].first.first << " " << ans2[i].second;
        //}
        //cout << ans2[i].first.first << " " << ans2[i].first.second << " " << ans2[i].second << endl;
    }
    //ll Answer = 0;
    /*for(int i = 0; i < ans.size(); i++){
        Answer += ans[i].second * ((sum2 - ans2[i].second + mod) % mod) % mod;
        Answer = Answer % mod;
    }*/
    //cout << sum1 << " " << sum2 << endl;
    ll Answer = (ways[t] * ways[t]) % mod;
    for(int i = 0; i < ans.size(); i++){
        Answer = (Answer - (ans[i].second * ans[i].second % mod) * (ans2[i].second * ans2[i].second % mod));
        if(Answer < 0){
            Answer += mod * mod;
        }
        Answer = Answer % mod;
    }
    cout << Answer << endl;
    return 0;
}