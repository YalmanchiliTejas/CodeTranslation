#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs            v.size()
#define ss            s.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii            pair<int, int>
#define int           long long
#define ull           unsigned long long
#define pb            push_back
#define mpp           make_pair
#define Okay          0
#define pi            3.14159

const int inf = 1e6;
const int cont = 1e18;
using namespace std;

vector<int>Graph[20];
int ans = 0;
int n, m;

void dfs(set<int>st, int u){
    if(st.count(u))return;
    st.insert(u);
    if(st.size() == n){
        ans++;
        return;
    }
    for(int i=0; i<Graph[u].size(); i++){
        int v = Graph[u][i];
        dfs(st, v);
    }
}

void solve(){

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        Graph[a].pb(b);
        Graph[b].pb(a);
    }
    set<int>st;
    dfs(st, 1);

    cout<<ans<<endl;
}

int32_t main() {
   Fast;
   int tst;

    solve();
    return Okay;
}

