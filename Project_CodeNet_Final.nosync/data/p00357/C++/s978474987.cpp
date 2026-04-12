#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

constexpr int INF = 1 << 29;

template<typename T>
bool chmin(T& a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector< vector<int> > g1(n);
    vector< vector<int> > g2(n);

    for(int i = 0 ; i < n ; ++i){
        int d;
        cin >> d;
        g1[i].emplace_back(min(i + d / 10, n - 1));
        g2[i].emplace_back(max(i - d / 10, 0));
        if(i > 0){
            g1[i].emplace_back(i - 1);
            g2[i - 1].emplace_back(i);
        }
    }

    vector<int> cost(n, INF);
    cost[0] = 0;
    queue< pair<int, int> > que;
    que.push({0, 0});

    while(!que.empty()){
        auto now = que.front();
        que.pop();

        if(cost[now.first] < now.second){
            continue;
        }

        for(auto to : g1[now.first]){
            if(chmin(cost[to], now.second + 1)){
                que.push({to, now.second + 1});
            }
        }
    }

    fill(cost.begin(), cost.end() - 1, INF);
    que.push({n - 1, cost[n - 1]});

    while(!que.empty()){
        auto now = que.front();
        que.pop();

        if(cost[now.first] < now.second){
            continue;
        }

        for(auto to : g2[now.first]){
            if(chmin(cost[to], now.second + 1)){
                que.push({to, now.second + 1});
            }
        }
    }

    if(cost[0] < INF){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    return 0;
}
