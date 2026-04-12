#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

int n;
int ans = 0;

void dfs(int c, int u, vector<bool> used, bool M[10][10]){
    if(u == n - 1){
        ans++;
        return;
    }
    rep(i,n){
        if(M[c][i] == 1 && used[i] == false){
            used[c] = true;
            dfs(i,u + 1,used,M);
        }
    }
}

int main(){
    int m;
    vector<bool> used(10);
    bool M[10][10] = {0};
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        M[a][b] = M[b][a] = 1;
    }
    dfs(0,0,used,M);
    cout << ans << endl;
}
