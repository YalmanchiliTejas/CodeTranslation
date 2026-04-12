#include<bits/stdc++.h>
#define ll long long 
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;


int n, m, ans;
vector<vector<int>> g(10);

void dfs(vector<int>v, int x){
    if(v.size() == n)ans++;


    for(auto i:g[x]){
        bool had = false;
        for(auto j:v){
            if(i == j) had = true;
        }
        if(had) continue;
        vector<int>u = v;
        u.push_back(i);
        dfs(u ,i);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = 0;
    vector<int>v={0};
    dfs(v, 0);
    cout << ans << endl;
}
