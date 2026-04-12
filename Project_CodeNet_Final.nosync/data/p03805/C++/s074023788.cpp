#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int N, M;
long long ans;
vector<vector<int>> G;
void dfs(int s, vector<bool> &isVisited, int cnt){
    if(cnt == N){
        ans++;
        return;
    }
    isVisited[s] = true;
    for(auto t : G[s]){
        if(isVisited[t]) continue;
        isVisited[t] = true;
        dfs(t, isVisited, cnt + 1);
        isVisited[t] = false;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    G.resize(N);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> isVisited(N);
    isVisited[0] = true;
    dfs(0, isVisited, 1);
    cout << ans << endl;
    return 0;
}
