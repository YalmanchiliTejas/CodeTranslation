#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;
bool fail = false;
vi adj[(int)2e5];
int dfs(int cur, int P){
    int cnt = 0;
    for(int child: adj[cur]){
        if(child == P)continue;
        cnt += dfs(child, cur);
    }
    if(cnt >=2)fail = true;
    return cnt == 0;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n;cin >> n;
    if(n == 1){
        cout << "First";
        return 0;
    }
    if(n == 2){
        cout << "Second";
        return 0;
    }
    FOR(i, n-1){
        int x, y;cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    FOR(i, n-1){
       if(adj[i].size() > 1){
        fail |= dfs(i, -1);
        break;
       } 
    }
    if(fail)cout << "First";
    else cout << "Second";
}


