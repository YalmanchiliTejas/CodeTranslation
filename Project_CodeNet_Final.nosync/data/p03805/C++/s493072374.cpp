#include<bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
//g++ -std==c++14
//setprecision(10)
int n, m, out, a, b;
vector <vector <int> > G;
vector <int> used;
void dfs(int a){
    bool h = true;
    for(int i = 0; i < n; i++)
        if(!used[i])
            h = false;
    if(h)
        out++;
    for(int i = 0; i < G[a].size(); i++){            
        int to = G[a][i];
        if(used[to])continue;
        used[to] = true;
        dfs(to);
        used[to] = false;
    }
}

int main(){
    cin >> n >> m;
    G = vector <vector <int> > (n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;    b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    used = vector <int> (n);
    used[0] = true;
    dfs(0);
    cout << out << endl;
}