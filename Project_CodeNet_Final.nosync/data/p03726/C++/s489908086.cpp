#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
bool used[100010];
bool flag = false;
vector<int> G[100010];

int dfs(int v, int p){
    for(auto u : G[v]){
        if(u != p) dfs(u, v);
    }
    if(!used[v]){
        used[v] = true;
        if(!used[p]) used[p] = true;
        else flag = true;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    used[0] = true;
    dfs(1, 0);
    cout << (flag ? "First" : "Second") << endl;
    return 0;
}