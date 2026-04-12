#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
int N,M;
vector<vector<int>> G;

void dfs(int v,vector<bool> &seen,int &res){
    bool end = true;
    for(int i=0;i<seen.size();i++){
        if(!seen[i]&&i!=v) end = false;
    }
    if(end){
        ++res;
        return;
    }
    seen[v] = true;
    for(auto nv:G[v]){
        if(seen[nv]) continue;
        dfs(nv,seen,res);
    }
    seen[v] = false;
}

int main(){
    cin >> N >> M;
    G.assign(N,vector<int>());
    rep(i,M){
        int a,b;cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> seen(N,false);
    int res = 0;
    dfs(0,seen,res);
    cout << res << endl;
}