#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)

int dfs(int v, vector<vector<int>> &G, vector<bool> &seen){
    // ベースケース
    // すべての点を通った
    bool end = true;
    REP(i, seen.size()){
        if (seen[i]==false && i!=v) end = false;
    }
    if(end){
        return 1;
    } 

    seen[v] = true;

    int result = 0;
    // 再帰ステップ
    for(auto nv :G[v]){
        if (seen[nv] == true) continue;
        result += dfs(nv, G, seen);
    }

    seen[v] =false;
    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>());
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a>>b; a--;b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<bool> seen(N, false);

    int cnt = dfs(0, G, seen);

    cout << cnt << endl;

   return 0;
}