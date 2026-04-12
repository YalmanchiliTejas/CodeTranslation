#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, k, n) for(int i = (int)k; i < (int)n; i++)
#define rrep(i, n) RREP(i, 0, n)
#define RREP(i, k, n) for(int i = (int)n-1; i > (int)k-1; i--)
#define mmax(start, end) *max_element(start, end)
#define mmin(start, end) *min_element(start, end)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " " << x << endl;

typedef long long ll;


vector<vector<int>> g(10,vector<int>(10,0));
int n,m;

int dfs(int v,int bit){
    int res = 0;
    bit |= (1<<(v-1));

    if(bit==((1<<n)-1)) return 1;

    rep(i,g[v].size()){
        if(g[v][i]==1){
            if((bit>>(i-1))&1) continue;//もしもビットが立っていたらcontinue;
            res += dfs(i,bit);
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);


    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    cout << dfs(1,0) << endl;
    return 0;
}