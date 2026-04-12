#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;
int ans;
void dfs(int i, vector<int> use){
    use[i] = 1;
    int flag = 0;
    for(int j:G[i]){
        if(use[j] == 0) {
            dfs(j, use);
            flag = 1;
        }
    }
    if(flag == 0){
        int flag2 = 0;
        for(int i = 0; i < (int)use.size(); i++){
            if(use[i] == 0) flag2 = 1;
        }
        if(flag2 == 0) ans++;
    }
}
int main(){
    int N, M;
    cin >> N >> M;
    G.resize(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans = 0;
    vector<int> used(N, 0);
    dfs(0, used);
    cout << ans << endl;
}