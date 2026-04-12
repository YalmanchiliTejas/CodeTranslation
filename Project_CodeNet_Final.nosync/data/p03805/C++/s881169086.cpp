#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 2e18;

typedef long long ll;

int n, m, a, b;
ll ans = 0;
vector<int> adjList[9];


void dfs(int x, int visited, int k){
    visited |= (1<<x);
    if(k == n){
        bool pos = 1;
        for(int i = 1; i <= n; i++){
            if(!(visited&(1<<i))){
                pos = 0;
            }
        }
        if(pos){
            ans++;
        }
    }
    else{
        for(int i = 0; i < adjList[x].size(); i++){

            if(!(visited&(1<<adjList[x][i]))){
                dfs(adjList[x][i], visited, k+1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    dfs(1, 0, 1);
    cout << ans;
}
