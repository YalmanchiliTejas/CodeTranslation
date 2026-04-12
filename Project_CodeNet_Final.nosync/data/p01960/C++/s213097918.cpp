#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n, -1);
    // 部分木のサイズ
    vector<int> dp_subtree(n, 0);
    // 親方向にカットエッジが伸びてる場合の部分木のサイズK以上の連結成分の個数
    vector<int> dp_cut_top(n, 0);
    auto dfs = [&](auto dfs, int v, int par) -> void {
        parent[v] = par;
        dp_subtree[v] = 1;
        for(int cld: adj[v]){
            if(cld == par) continue;
            dfs(dfs, cld, v);
            dp_subtree[v] += dp_subtree[cld];
        }
        int tmpnum = 0;
        for(int cld: adj[v]){
            if(cld == par) continue;
            if(dp_subtree[cld] >= k) tmpnum++;
        }
        dp_cut_top[v] = tmpnum;
        for(int cld: adj[v]){
            if(cld == par) continue;
            int loss = (dp_subtree[cld]>=k)? 1: 0;
            int gain = dp_cut_top[cld];
            dp_cut_top[v] = max(dp_cut_top[v], tmpnum -loss +gain);
        }
    };
    dfs(dfs, 0, -1);
    int ans = 0;
    for(int i=0; i<n; i++){
        // 頂点iを取り除いた時のK連結成分数
        int sub = 0;
        if(n-dp_subtree[i] >= k) sub++;
        // 子方向にエッジを伸ばしたときの増減
        vector<int> gain;
        for(int cld: adj[i]){
            if(cld == parent[i]) continue;
            int subtree_ok = (dp_subtree[cld]>=k)? 1: 0;
            if(subtree_ok == 1) sub++;
            gain.push_back(dp_cut_top[cld] -subtree_ok);
        }
        sort(gain.begin(), gain.end(), greater<int>());
        if(gain.empty()) continue; // 相異なる2点を選ぶ、に違反
        if(gain.size() >= 1u){
            ans = max(ans, sub+gain[0]);
        }
        if(gain.size() >= 2u){
            ans = max(ans, sub+gain[0]+gain[1]);
        }
    }
    cout << ans << endl;
    return 0;
}

