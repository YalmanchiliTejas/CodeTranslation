#include <iostream>
#include <vector>
#include <queue>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;
using namespace std;

vector<bool> visited(8, false);
vector<vector<int>> edges;

bool all_visited(int num){
    rep(i, num){
        if(! visited[i]){
            return false;
        }
    }
    return true;

}

int dfs(int now, int num){
    int ans = 0;
    if(all_visited(num)){
        return 1;
    }
    rep(i, edges[now].size()){
        int e = edges[now][i];
        if(! visited[e]){
            visited[e] = true;
            ans += dfs(e, num);
            visited[e] = false;
        }
    }
    return ans;
}

int main(){
    int N, M;
    cin >> N >> M;
    edges.resize(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    visited[0] = true;
    int ans = dfs(0, N);
    cout << ans << endl;
    return 0;
}
