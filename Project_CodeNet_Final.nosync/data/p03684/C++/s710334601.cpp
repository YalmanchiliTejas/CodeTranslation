#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> v1(N), v2(N);
    for(int i=0; i<N; i++){
        v1[i].second = i;
        v2[i].second = i;
    }
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        v1[i].first = x;
        v2[i].first = y;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<vector<pair<int, int>>> G(N);
    for(int i=0; i<N-1; i++){
        int id1 = v1[i].second, id2 = v1[i+1].second;
        int cost = abs(v1[i].first - v1[i+1].first);
        G[id1].push_back(make_pair(cost, id2));
        G[id2].push_back(make_pair(cost, id1));
    }
    for(int i=0; i<N-1; i++){
        int id1 = v2[i].second, id2 = v2[i+1].second;
        int cost = abs(v2[i].first - v2[i+1].first);
        G[id1].push_back(make_pair(cost, id2));
        G[id2].push_back(make_pair(cost, id1));
    }

    int cnt = 0;
    long long ans = 0;
    vector<int> isVisited(N, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while(cnt < N){
        pair<int, int> tp = pq.top();
        pq.pop();
        if(isVisited[tp.second]) continue;
        cnt++;
        isVisited[tp.second] = true;
        ans += tp.first;
        for(auto edge : G[tp.second])
            pq.push(edge);
    }
    cout << ans << endl;

    return 0;
}