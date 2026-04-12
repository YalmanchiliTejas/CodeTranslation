#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m,res = 0;
int a[20][20] = {};

void dfs(int i,vector<bool> f){
    
    bool F = true;
    for(int j = 0; j < n; j++)
        if(!f[j]) F = false;
    if(F) res++;
    
    for(int j = 0; j < n; j++){
        if(a[i][j] && !f[j] ){
            f[j] = true;
            dfs(j,f);
            f[j] = false;
        }
    }
    
}

void solve(){
    vector<bool> f(n);
    f[0] = true;
    dfs(0,f);
}


int main(void){
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int b,c;
        cin >> b >> c;
        b--;c--;
        a[b][c] = 1;
        a[c][b] = 1;
    }
    
    solve();
    
    cout << res << endl;
    
}
