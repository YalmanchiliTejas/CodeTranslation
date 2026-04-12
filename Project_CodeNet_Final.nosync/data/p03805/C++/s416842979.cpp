#include <bits/stdc++.h>

#define int long long

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define FORR(i,m,n) for(int i=m;i>=n;i--)
#define pb(x) push_back(x) 
#define SORT(x) sort((x).begin(),(x).end())
#define INF 99999999999
 
using namespace std;


vector<vector<int> > v(100, vector<int>());
int n, m;
int cnt;

int bfs(int u, vector<bool> flag){
    bool f=true;
    REP(i, n){
        if(!flag[i+1]){
            f=false;
        }
    }

    if(f){
        cnt++;
        return 0;
    }

    REP(i, v[u].size()){
        if(!flag[v[u][i]]){
            flag[v[u][i]]=true;
            bfs(v[u][i], flag);
            flag[v[u][i]]=false;
        }
    }

    return 0;
}

int32_t main(){
    cin >> n >> m;
    REP(i, m){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    
    cnt=0;
    vector<bool> flag(100, false);
    flag[1]=true;
    bfs(1, flag);

    cout << cnt << endl;
}