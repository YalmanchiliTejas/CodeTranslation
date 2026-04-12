#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
using Graph = vector<vector<int>>;
using Graph_Wei = vector<vector<pair<int,int>>>;
using ll = long long;

vector<bool> seen;

Graph G;
void dfs(int v,vector<bool>& seen,int& res){

    //現在の頂点以外が訪問済みならパス追加して処理終了
    bool end = true;
    for(int i=0;i < seen.size();i++) if(!seen[i] && v != i) end = false;
    if(end){
        res++;
        return;
    }

    seen[v] = true;
    for(auto nv:G[v]){
        if(seen[nv]) continue;
        dfs(nv,seen,res);

    }
    seen[v] = false;
}


int main() {
    int n,m;
    cin >> n >> m;
    //n個の配列で初期化
    G.assign(n, vector<int>());
    for(int i=0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);

    }

    int res=0;
    seen.assign(n,false);
    dfs(0,seen,res);

    cout << res << endl;
    



    return 0;

}