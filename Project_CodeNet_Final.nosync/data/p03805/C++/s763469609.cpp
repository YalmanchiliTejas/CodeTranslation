#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> seen;
vector<vector<int>> g;
int n, m;   
void dfs(int x, int &cnt){
    bool f=true;
    for(int i=0; i<n; i++)
        if(!seen[i] && i!=x) f=false;
    if(f){
        cnt+=1; return;
    }
    seen[x] = true;
    
    for(auto next: g.at(x)){
        if(seen[next]) continue;
        dfs(next, cnt);
    }
    seen[x] = false;

}


int main(){
    cin >> n >> m;
    g.assign(n, vector<int>());
    seen.assign(n, false);

    for(int i=0; i<m; i++){
        int a, b;   cin >> a >> b;
        a--;    b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }
    int cnt=0;
    dfs(0, cnt);
    cout << cnt << endl;
}